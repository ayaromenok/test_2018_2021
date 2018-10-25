// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

#include "qcvobject.h"
#include "share.h"
#include "cvres.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>
#include "opencv2/core.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/superres.hpp"
#include "opencv2/superres/optical_flow.hpp"
#include "opencv2/opencv_modules.hpp"
//#include <opencv2/core.hpp>
//#include <opencv2/core/utils/trace.hpp>
//#include <opencv2/core/opencl/opencl_info.hpp>
#include <QImage>
#include <QFileInfo>
QCvObject::QCvObject(QObject *parent) : QObject(parent)
{
    CVQT_TIMESTAMP();

    _testCPU = 0;
    _testCL = 0;
    _testVal = 0;

    qDebug() << "OpenCV is" << CV_VERSION;
    cv::ocl::Context ctx = cv::ocl::Context::getDefault();
    if (!ctx.ptr())
    {
        qDebug() << "\t\t\tOpenCL is not available";
    } else {
        cv::ocl::Device device = cv::ocl::Device::getDefault();

        qDebug() << "\t\t\tOpenCL device is: "<< device.OpenCLVersion().c_str();
        qDebug() << "\t\t\tOpenCL/C device is: "<< device.OpenCL_C_Version().c_str();
        qDebug() << "\t\t\tOpenCL" << device.driverVersion().c_str();
    }
    CvRes::videoAvi();
}

QCvObject::~QCvObject()
{
    CVQT_TIMESTAMP();
}


qint64
QCvObject::testCPU()
{
    CVQT_TIMESTAMP();

    return _testCPU;
}

void
QCvObject::setTestCPU(qint64 value)
{
    CVQT_TIMESTAMP();

    //perfTest(false, false, (int)value);
    perfSuperResTest(false, false, (int)value);
    _testCPU = _testVal;

    emit testCPUChanged(_testCPU);
}

qint64
QCvObject::testCL()
{
    CVQT_TIMESTAMP();

    return _testCL;
}

void
QCvObject::setTestCL(qint64 value)
{
    CVQT_TIMESTAMP();

    //perfTest(true, false, (int)value);
    perfSuperResTest(true, false, (int)value);
    _testCL = _testVal;
    emit testCLChanged(_testVal);
}

void
QCvObject::perfTest(bool bCL, bool bCuda, int count)
{
    CVQT_TIMESTAMP();

    CvQtPerf perf;
    //CvRes::imageRgb();
    //cv::Mat imIn = cv::imread("./imageRgb.png");
    cv::Mat imIn = cv::imread("./test4k.png");
    _testVal = 0;

    if (imIn.rows > 0){
        qDebug() << "image" << imIn.rows << "x" << imIn.cols;
        cv::UMat imInUMat, imOutUMat;
        imIn.copyTo(imInUMat);
        if (bCuda){
            qDebug() << "CUDA test not implemented yet";
        }
        else{
            cv::ocl::setUseOpenCL(bCL);
            if (bCL){
                qDebug() << "CL mode";
            } else {
                qDebug() << "CPU mode";
            }
        }

        perf.start();
        for (int i=0; i< count; i++){
            cv::cvtColor(imInUMat, imOutUMat, cv::COLOR_RGB2HSV);
        }
        _testVal = perf.stop();
    } else {
        qDebug() << "can't read input image, skipping test";
        _testVal = 0;
    }
}

void
QCvObject::perfSuperResTest(bool bCL, bool bCuda, int count)
{
    CVQT_TIMESTAMP();
    CvQtPerf perf;

    const std::string inputVideoName = "./car.avi";
    const std::string outputVideoName = "./out.avi";
    const int scale = 4;
    const int iterations = count;
    const int temporalAreaRadius = 4;
    const std::string optFlow = "farneback";
    cv::Ptr<cv::superres::SuperResolution> superRes;
    cv::Ptr<cv::superres::DenseOpticalFlowExt> of;
    if(bCuda){
        superRes = cv::superres::createSuperResolution_BTVL1_CUDA();
        of = cv::superres::createOptFlow_Farneback_CUDA();
        qDebug() << "cuda path";
    } else{
        superRes = cv::superres::createSuperResolution_BTVL1();//UMat should be used
        of = cv::superres::createOptFlow_Farneback();
        qDebug() << "cpu/CL path";
    }


    superRes->setOpticalFlow(of);
    superRes->setScale(scale);
    superRes->setIterations(iterations);
    superRes->setTemporalAreaRadius(temporalAreaRadius);

    cv::Ptr<cv::superres::FrameSource> frameSource;


    if (bCuda)
    {
        // Try to use gpu Video Decoding
        try
        {
            frameSource = cv::superres::createFrameSource_Video_CUDA(inputVideoName);
            cv::Mat frame;
            frameSource->nextFrame(frame);
        }
        catch (const cv::Exception&)
        {
            frameSource.release();
        }
    }
    if (!frameSource){
        QFileInfo fInfo;
        fInfo.setFile(inputVideoName.c_str());
        qDebug() << "file is" << fInfo.size() << "bytes";
        frameSource = cv::superres::createFrameSource_Video(inputVideoName);
        //frameSource = cv::superres::createFrameSource_Empty();
    }


    // skip first frame, it is usually corrupted
    {
        if (bCL){
            cv::UMat frame;
            frameSource->nextFrame(frame);
        }
        else {
            cv::Mat frame;
            frameSource->nextFrame(frame);
        }

        qDebug() << "Input           : " << inputVideoName.c_str() ;
        qDebug() << "Scale factor    : " << scale ;
        qDebug()  << "Iterations      : " << iterations ;
        qDebug()  << "Temporal radius : " << temporalAreaRadius;
        qDebug()  << "Optical Flow    : " << optFlow.c_str() ;
        if (bCuda)
            qDebug()  << "Mode            : CUDA";
        else if (bCL)
            qDebug()  << "Mode            : OpenCL";
        else
            qDebug()  << "Mode            : CPU";

    }

    superRes->setInput(frameSource);
    cv::VideoWriter writer;
    perf.start();

    for (int i = 0; i<iterations; ++i)
    {

        if (bCL){
            cv::UMat result;
            superRes->nextFrame(result);
        }
        else {
            cv::Mat result;
            superRes->nextFrame(result);
        }

        //superRes->nextFrame(result);

//        if (result.empty())
//            break;

        //                imshow("Super Resolution", result);
        qDebug() << "#" << i;

//        if (!outputVideoName.empty())
//        {
//            if (!writer.isOpened())
//                writer.open(outputVideoName, cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), 25.0, result.size());
//            writer << result;
//        }
    }

    _testVal = perf.stop();
}
