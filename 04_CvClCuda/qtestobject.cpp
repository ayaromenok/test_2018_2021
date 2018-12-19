#include "qtestobject.h"
#include "cvtestobject.h"

#include <opencv2/core.hpp>
#include <QDebug>
#include <QImage>

QTestObject::QTestObject(QObject *parent) : QObject(parent)
{
    qInfo() << __PRETTY_FUNCTION__;
    _cto = new CvTestObject;
}

QTestObject::~QTestObject()
{
    qInfo() << __PRETTY_FUNCTION__;
    delete _cto;
}

bool
QTestObject::testCPU()
{
    qInfo() << __PRETTY_FUNCTION__;
    cv::Mat img;
    QImage qImg;
    if (qImg.load(":/lena.jpg")){
        img = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
    } else {
        qWarning() << "can't read input file";
        return false;
    }
    if (img.ptr()){
        qDebug() << "CPU: " << _cto->testCPU(img) << "msec";
    } else {
        qWarning() << "cv::Mat not loaded correctly";
        return false;
    }
    return true;
}

bool
QTestObject::testCL()
{
    qInfo() << __PRETTY_FUNCTION__;
    cv::Mat inImg;
    cv::UMat img;
    QImage qImg;
    if (qImg.load(":/lena.jpg")){
        inImg = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
        inImg.copyTo(img);
    } else {
        qWarning() << "can't read input file";
        return false;
    }
    if (img.dims > 0){
        qDebug() << "CL: " << _cto->testCL(img) << "msec";
    } else {
        qWarning() << "cv::Mat not loaded correctly";
        return false;
    }
    return true;
}

bool
QTestObject::testCUDA()
{
    qInfo() << __PRETTY_FUNCTION__;
    cv::Mat img;
    QImage qImg;
    if (qImg.load(":/lena.jpg")){
        img = cv::Mat(cv::Size(qImg.width(),qImg.height()), CV_8UC4, qImg.bits());
    } else {
        qWarning() << "can't read input file";
        return false;
    }
    if (img.ptr()){
        qDebug() << "CUDA: " << _cto->testCUDA(img) << "msec";
    } else {
        qWarning() << "cv::Mat not loaded correctly";
        return false;
    }

    return false;
}
