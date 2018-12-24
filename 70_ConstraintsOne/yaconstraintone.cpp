// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#include <math.h>
#include "yaconstraintone.h"
#include <QDebug>
YaConstraintOne::YaConstraintOne(QObject *parent) : QObject(parent)
{
    //qDebug() << __PRETTY_FUNCTION__;
    _lengthf = 0.0f;
    _frontPerimf = 0.0f;
    _backPerimf = 0.0f;
}
YaConstraintOne::~YaConstraintOne()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void
YaConstraintOne::setParams(float length,
                           float frontWidth, float frontHeight,
                           float backWidth, float backHeight,
                           float vertShift)
{
    qDebug() << __PRETTY_FUNCTION__;

    _lengthf = length;
    _frontWidthf = frontWidth;
    _frontHeightf = frontHeight;
    _backWidthf = backWidth;
    _backHeightf = backHeight;
    _vertShiftf = vertShift;
    calcPerimeters();
}
void
YaConstraintOne::calcPerimeters()
{
    //qDebug() << __PRETTY_FUNCTION__;

    _frontPerimf =(float) M_PI*0.5*(3*(_frontWidthf+_frontHeightf)- sqrt(
                                    (3*_frontWidthf+_frontHeightf)*
                                    (_frontWidthf+3*_frontHeightf)));

    _backPerimf =(float) M_PI*0.5*(3*(_backWidthf+_backHeightf)- sqrt(
                                    (3*_backWidthf+_backHeightf)*
                                    (_backWidthf+3*_backHeightf)));
}

float
YaConstraintOne::getLength()
{
    qDebug() << __PRETTY_FUNCTION__;
    return _lengthf;
}

float
YaConstraintOne::getFrontPerimeter()
{
    qDebug() << __PRETTY_FUNCTION__ << _frontPerimf;
    return _frontPerimf;
}

float
YaConstraintOne::getBackPerimeter()
{
    qDebug() << __PRETTY_FUNCTION__ << _backPerimf;
    return _backPerimf;
}

float
YaConstraintOne::getConusTopPoint()
{
    float tp = 0.0f;
    tp = (1/(std::min(_frontPerimf, _backPerimf)/std::max(_frontPerimf,_backPerimf)))
            *_lengthf;
    //tp = atanf((_frontPerimf - _backPerimf)/_lengthf)*180/M_PI;
    qDebug() << __PRETTY_FUNCTION__ << tp;
    return tp;
}

float
YaConstraintOne::getConusAngle()
{
    float ta = 0.0f;
    ta = atanf((_frontPerimf - _backPerimf)/_lengthf)*180/M_PI;
    qDebug() << __PRETTY_FUNCTION__ << ta;
    return ta;
}
