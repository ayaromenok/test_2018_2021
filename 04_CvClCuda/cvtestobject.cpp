#include "cvtestobject.h"
#include <iostream>
#include <opencv2/opencv.hpp>


CvTestObject::CvTestObject()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
}

double
CvTestObject::testCPU(const cv::Mat &img, int scale, bool isSaveResult)
{
    cv::TickMeter pc;
    cv::Mat inGray, gray;

    cv::cvtColor(img, inGray, cv::COLOR_BGR2GRAY);
    cv::resize(inGray, gray,cv::Size(img.rows*scale, img.cols*scale));

    pc.start();
    cv::Canny(gray, gray, 0, 50);
    pc.stop();


    if (isSaveResult){
        cv::imwrite("testCPU.png", gray);
    }
    return pc.getTimeMilli();
}

double
CvTestObject::testCL(const cv::UMat &img, int scale, bool isSaveResult)
{
    cv::TickMeter pc;
    cv::UMat inGray, gray;

    cv::cvtColor(img, inGray, cv::COLOR_BGR2GRAY);
    cv::resize(inGray, gray,cv::Size(img.rows*scale, img.cols*scale));

    pc.start();
    cv::Canny(gray, gray, 0, 50);
    pc.stop();

    if (isSaveResult){
        cv::imwrite("testCL.png", gray);
    }

    return pc.getTimeMilli();
}

double
CvTestObject::testCUDA(const cv::Mat &img, int scale, bool isSaveResult)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    //std::cout << "test image: " << img.cols << "x" << img.rows << std::endl;
    cv::TickMeter pc;
    cv::Mat inGray, gray;
    cv::cuda::GpuMat imgOutCu;


    cv::cvtColor(img, inGray, cv::COLOR_BGR2GRAY);
    cv::resize(inGray, gray, cv::Size(img.rows*scale, img.cols*scale));

    const cv::cuda::GpuMat inGrayCu(gray);
    cv::Ptr<cv::cuda::CannyEdgeDetector> canny
            = cv::cuda::createCannyEdgeDetector(0, 50, 3, false);

    pc.start();
    canny->detect(inGrayCu, imgOutCu);
    pc.stop();


    if (isSaveResult){
        const cv::Mat imgOut(imgOutCu);
        cv::imwrite("testCUDA.png", imgOut);
    }
    return pc.getTimeMilli();
}
