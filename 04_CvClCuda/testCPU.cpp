#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

double testImage(const string &inImage){
    Mat img, gray;
    cv::TickMeter pc;
    
    imread(inImage, IMREAD_COLOR).copyTo(img);
    
    pc.start();
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);
    pc.stop();
    
    return pc.getTimeMilli();
}

double testImageCL(const string &inImage){
    UMat img, gray; // CL via Transparent API
    cv::TickMeter pc;
    
    imread(inImage, IMREAD_COLOR).copyTo(img);
    
    pc.start();
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray,Size(7, 7), 1.5);
    Canny(gray, gray, 0, 50);
    pc.stop();
    
    return pc.getTimeMilli();
}
 
int main(int argc, char** argv)
{
    string strLena512("lena512.jpg");
    string strLena1k("lena1k.jpg");
    string strLena2k("lena2k.jpg");
    string strLena4k("lena4k.jpg");
    
    cout << "Test CPU:" << endl;
    cout << "time: " << testImage(strLena512) << " msec" << endl;   
    cout << "time: " << testImage(strLena1k) << " msec" << endl;   
    cout << "time: " << testImage(strLena2k) << " msec" << endl;   
    cout << "time: " << testImage(strLena4k) << " msec" << endl;   
    cout << "Test GPU/CL:" << endl;
    cout << "time: " << testImageCL(strLena512) << " msec" << endl;   
    cout << "time: " << testImageCL(strLena1k) << " msec" << endl;   
    cout << "time: " << testImageCL(strLena2k) << " msec" << endl;   
    cout << "time: " << testImageCL(strLena4k) << " msec" << endl;   
    return 0;
}
