// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

#include "cvres.h"
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include "share.h"
#include <opencv2/imgproc.hpp>

CvRes::CvRes(QObject *parent) : QObject(parent)
{
    CVQT_TIMESTAMP();
}

bool
CvRes::imageRgb()
{
    return getImage(ImgType::Rgb);
}

bool
CvRes::imageRgbFull()
{
    return getImage(ImgType::Rgb);
}

bool
CvRes::imageRgbPart()
{
    return getImage(ImgType::RgbPart);
}

bool
CvRes::imageRgbStereoLeft()
{
    return getImage(ImgType::RgbStereoLeft);
}

bool
CvRes::imageRgbStereoRight()
{
    return getImage(ImgType::RgbStereoRight);
}

bool
CvRes::imageChecked12x12()
{
    return getImage(ImgType::Checked12x12);
}
bool
CvRes::videoAvi()
{
    return getImage(ImgType::videoAvi);
}
bool
CvRes::getImage(ImgType type)
{
    CVQT_TIMESTAMP();

    bool result = false;

    switch (type) {
    case ImgType::Rgb:{
        result = getImage(":/data/len_full.png", "./imageRgb.png");
        break;
    }
    case ImgType::RgbPart:{
        result = getImage(":/data/len_part.png", "./imageRgbPart.png");
        break;
    }
    case ImgType::RgbStereoLeft:{
        result = getImage(":/data/640x480x24Left.png", "./imageRgbStereoLeft.png");
        break;
    }
    case ImgType::RgbStereoRight:{
        result = getImage(":/data/640x480x24Right.png", "./imageRgbStereoRight.png");
        break;
    }
    case ImgType::Checked12x12:{
        result = getImage(":/data/imgChecked_12x12.png", "./imageChecked12x12.png");
        break;
    }
    case ImgType::videoAvi:{
        result = getImage(":/data/car.avi", "./car.avi");
        break;
    }
    default:{
        qDebug() << "unsupported image type";
        result = false;
        break;
    }
    }

    return result;
}
bool
CvRes::getImage(QString inName, QString outName)
{
    CVQT_TIMESTAMP();

    bool result = false;

    QFile fileIn, fileOut;
    QDir dir;
    fileIn.setFileName(inName);
    fileOut.setFileName(outName);


    if (fileIn.exists()) {
        if (!fileOut.exists()) {
            if (fileIn.copy(outName))
            {
                qDebug() << QDateTime::currentMSecsSinceEpoch()
                         << outName << "is OK";
                result = true;
            } else {
                qDebug() << QDateTime::currentMSecsSinceEpoch()
                         << outName << "is MISSING";
                result = false;
            }
        } else {
            qDebug() << QDateTime::currentMSecsSinceEpoch()
                     << outName << "is OK/already exist";
            result = true;
        }
    } else {
        qDebug() << QDateTime::currentMSecsSinceEpoch()
                 << "predefined  file not found - check Qt resources";
        result = false;
    }
    return result;
}

cv::Mat
CvRes::imageQtToCv(QImage &imageIn)
{
    cv::Mat imageOut(cv::Size(imageIn.width(), imageIn.height()),
                              CV_8UC4, imageIn.bits());
    return imageOut;
}

QImage
CvRes::imageCvToQt(cv::Mat &imageIn)
{
    QImage imageOut(imageIn.cols, imageIn.rows,  QImage::Format_RGB888);
    cv::Mat imageCvOut(cv::Size(imageIn.cols,imageIn.rows),
                       CV_8UC3, imageOut.bits());
    cv::cvtColor(imageIn, imageCvOut, cv::COLOR_BGR2RGB);
    return imageOut;
}
