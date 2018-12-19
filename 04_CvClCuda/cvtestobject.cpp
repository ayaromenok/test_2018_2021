#include "cvtestobject.h"
#include <iostream>

CvTestObject::CvTestObject()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int
CvTestObject::testCPU(const cv::Mat &img)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "test image: " << img.cols << "x" << img.rows << std::endl;
    return 0;
}

int
CvTestObject::testCL(const cv::UMat &img)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "test image: " << img.cols << "x" << img.rows << std::endl;
    return 0;
}

int
CvTestObject::testCUDA(const cv::Mat &img)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << "test image: " << img.cols << "x" << img.rows << std::endl;
    return 0;
}
