#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
 
int main(int argc, char** argv)
{
    Mat img, gray;
    int64 e1, e2, time;
    imread("lena4k.jpg", IMREAD_COLOR).copyTo(img);

    e1= cv::getTickCount(); 
    
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);
    
    e2 = cv::getTickCount();
    time = (1000*(e2-e1))/cv::getTickFrequency();
    std::cout << "time: " << time << std::endl;

    return 0;
}
