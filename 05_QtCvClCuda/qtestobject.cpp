// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE
#include "qtestobject.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core/opencl/opencl_info.hpp>

QTestObject::QTestObject(QObject *parent) : QObject(parent)
{

}

void
QTestObject::testCPU(){
    qInfo() << __FUNCTION__;
    getCpuInfo();
    cv::Mat img, gray;
    cv::TickMeter pc;

    cv::imread("lena.jpg", cv::IMREAD_COLOR).copyTo(img);
    if(img.ptr()){
        qInfo() << "image" << img.cols << "x" << img.rows;
    } else {
        qWarning() << "image can't be read";
        return;
    }
    pc.start();
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(7,7), 1.5);
    cv::Canny(gray, gray, 0, 50);
    pc.stop();

    qInfo() << "time" << pc.getTimeMicro() << "mk sec";
}

void
QTestObject::testCL(){
    qInfo() << __FUNCTION__;
    getClInfo();
    qInfo() << __FUNCTION__;
    getCpuInfo();
    cv::UMat img, gray;
    cv::TickMeter pc;

    cv::imread("lena.jpg", cv::IMREAD_COLOR).copyTo(img);
    if(img.dims > 0){
        qInfo() << "image" << img.cols << "x" << img.rows;
    } else {
        qWarning() << "image can't be read";
        return;
    }
    pc.start();
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gray, gray, cv::Size(7,7), 1.5);
    cv::Canny(gray, gray, 0, 50);
    pc.stop();

    qInfo() << "time" << pc.getTimeMicro() << "mk sec";
}

void
QTestObject::testCUDA(){
    qInfo() << __FUNCTION__;
    getCudaInfo();
}

void
QTestObject::getCpuInfo(){
    qInfo() << __FUNCTION__;
}

void
QTestObject::getClInfo(){
    qInfo() << __FUNCTION__;
    cv::ocl::Context ctx = cv::ocl::Context::getDefault();

    if(ctx.ptr()) {
        cv::ocl::Device device = cv::ocl::Device::getDefault();
        if (device.ptr()){
            qInfo() << "CL name" << device.name().c_str();
            qInfo() << "CL version" << device.version().c_str();

            qInfo() << "CL workGroupSize" << device.maxWorkGroupSize();
            qInfo() << "CL global memory" << device.globalMemSize();
        } else {
            qWarning() << "Something wrong with default CL device";
            return;
        }

    } else {
        qWarning() << "OpenCL not available.";
        return;
    }
}

void
QTestObject::getCudaInfo(){
    qInfo() << __FUNCTION__;
}
