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
}

void
QTestObject::testCL(){
    qInfo() << __FUNCTION__;
    getClInfo();
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
