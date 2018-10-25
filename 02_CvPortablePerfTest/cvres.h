// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

#ifndef CVRES_H
#define CVRES_H

#include <QObject>
#include <QImage>
#include <opencv2/core.hpp>

class CvRes : public QObject
{
    Q_OBJECT
enum class ImgType {Rgb, RgbPart, RgbStereoLeft, RgbStereoRight, Checked12x12, videoAvi, Unknown};
public:
    explicit CvRes(QObject *parent = nullptr);
    static bool imageRgb();
    static bool imageRgbFull();
    static bool imageRgbPart();
    static bool imageRgbStereoLeft();
    static bool imageRgbStereoRight();
    static bool imageChecked12x12();
    static bool videoAvi();

    static cv::Mat imageQtToCv(QImage &imageIn);
    static QImage imageCvToQt(cv::Mat &imageIn);

signals:

public slots:
private:
    static bool getImage(ImgType type);
    static bool getImage(QString inName, QString outName);
};

#endif // CVRES_H
