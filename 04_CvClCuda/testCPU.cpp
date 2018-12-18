#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/opencl/opencl_info.hpp>
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
    
    string outImage(inImage);
    outImage.insert(0,"out_cpu_");
    imwrite(outImage,gray);

    
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

    string outImage(inImage);
    outImage.insert(0,"out_cl_");
    imwrite(outImage,gray);
    
    return pc.getTimeMilli();
}

void dumpCLInfo(){
    //cv::dumpOpenCLInformation();
    
    cv::ocl::Context ctx = cv::ocl::Context::getDefault();
    if (!ctx.ptr())
    {
        cout << "\t\t\tOpenCL is not available" << endl;
    } else {
        cv::ocl::Device device = cv::ocl::Device::getDefault();

        cout << "\t\t\tOpenCL device is: "<< device.OpenCLVersion().c_str() << endl;
        cout << "\t\t\tOpenCL/C device is: "<< device.OpenCL_C_Version().c_str() << endl;
        cout << "\t\t\tOpenCL: " << device.driverVersion().c_str() << endl;
        cout << "\t\t\tWorkGroupSize: " << device.maxWorkGroupSize() << endl;
    }
} 
    
int main(int argc, char** argv)
{
    string strLena512("lena512.jpg");
    string strLena1k("lena1k.jpg");
    string strLena2k("lena2k.jpg");
    string strLena4k("lena4k.jpg");
    
    dumpCLInfo();

    cout << "warm up CPU/CL " << endl;
    testImage(strLena512);   
    testImageCL(strLena512);
    
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
