#include "qtestobject.h"
#include "cvtestobject.h"

#include <opencv2/core.hpp>
#include <opencv2/core/opencl/opencl_info.hpp>

#include <QDebug>
#include <QImage>

QTestObject::QTestObject(QObject *parent) : QObject(parent)
{
    //qInfo() << __PRETTY_FUNCTION__;
    _cto = new CvTestObject;
}

QTestObject::~QTestObject()
{
    //qInfo() << __PRETTY_FUNCTION__;
    delete _cto;
}

double
QTestObject::testCPU(int scale, bool isSaveResult, bool isShowInfo)
{
    //qInfo() << __PRETTY_FUNCTION__;
    cv::Mat img;
    QImage qImg;
    double result = 0.0;

    if (qImg.load(":/lena.jpg")){
        img = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
    } else {
        qWarning() << "can't read input file";
        return -0.1;
    }
    if (img.ptr()){
        result = _cto->testCPU(img, scale, isSaveResult);
        if (isShowInfo){
            qDebug() << "CPU: " << result << "msec";
        }
    } else {
        qWarning() << "cv::Mat not loaded correctly";
        return -0.2;
    }
    return result;
}

double
QTestObject::testCL(int scale, bool isSaveResult, bool isShowInfo, bool isShowCLInfo)
{
    //qInfo() << __PRETTY_FUNCTION__;
    cv::Mat inImg;
    cv::UMat img;
    QImage qImg;
    double result = 0.0;

    cv::ocl::Context ctx = cv::ocl::Context::getDefault();
    if (!ctx.ptr())
    {
        std::cout << "\t\t\tOpenCL is not available" << std::endl;
        return -0.1;
    } else {
        cv::ocl::Device device = cv::ocl::Device::getDefault();
        if (isShowCLInfo){
            qDebug() << "\tOpenCL device is: "<< device.OpenCLVersion().c_str();
            qDebug()  << "\tOpenCL drievr version: " << device.driverVersion().c_str();
            qDebug()  << "\tWorkGroupSize: " << device.maxWorkGroupSize();
        }
        if (qImg.load(":/lena.jpg")){
            inImg = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
            inImg.copyTo(img);
        } else {
            qWarning() << "can't read input file";
            return -0.2;
        }
        if (img.dims > 0){
            result = _cto->testCL(img, scale, isSaveResult);
            if (isShowInfo){
                qDebug() << "CL: " << result << "msec";
            }
        } else {
            qWarning() << "cv::Mat not loaded correctly";
            return -0.3;
        }
    }
    return result;
}

double
QTestObject::testCUDA(int scale, bool isSaveResult, bool isShowInfo)
{
    //qInfo() << __PRETTY_FUNCTION__;
    cv::Mat img;
    QImage qImg;
    double result = 0.0;

    if (qImg.load(":/lena.jpg")){
        img = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
    } else {
        qWarning() << "can't read input file";
        return -0.2;
    }
    if (img.ptr()){
        result = _cto->testCUDA(img, scale, false);
        if (isShowInfo){
            qDebug() << "CUDA: " << result << "msec";
        }
    } else {
        qWarning() << "cv::Mat not loaded correctly";
        return 0.3;
    }

    return result;
}
