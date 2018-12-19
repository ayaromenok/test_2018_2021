#ifndef CVTESTOBJECT_H
#define CVTESTOBJECT_H
#include <opencv2/core.hpp>


class CvTestObject
{
public:
    CvTestObject();
    int testCPU(const cv::Mat &img);
    int testCL(const cv::UMat &img);
    int testCUDA(const cv::Mat &img);
};

#endif // CVTESTOBJECT_H
