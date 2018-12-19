#ifndef CVTESTOBJECT_H
#define CVTESTOBJECT_H
#include <opencv2/core.hpp>


class CvTestObject
{
public:
    CvTestObject();
    double testCPU(const cv::Mat &img, int scale = 1, bool isSaveResult = false);
    double testCL(const cv::UMat &img, int scale = 1, bool isSaveResult = false);
    double testCUDA(const cv::Mat &img, int scale = 1, bool isSaveResult = false);
};

#endif // CVTESTOBJECT_H
