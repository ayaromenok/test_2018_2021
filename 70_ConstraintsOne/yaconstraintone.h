// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#ifndef YACONSTRAINTONE_H
#define YACONSTRAINTONE_H

#include <QObject>

class YaConstraintOne : public QObject
{
    Q_OBJECT
public:
    explicit YaConstraintOne(QObject *parent = nullptr);
    ~YaConstraintOne();
    void setParams( float length = 5.0f,
                    float frontWidth = 3.0f, float frontHeight = 2.0f,
                    float backWidth = 2.0f, float backHeight = 1.0f,
                    float vertShift = 0.0f );

    float getLength();
    float getFrontPerimeter();
    float getBackPerimeter();
    float getConusTopPoint();
    float getConusAngle();
signals:

public slots:

private:
    void            calcPerimeters();
    float           _lengthf;
    float           _frontWidthf;
    float           _frontHeightf;
    float           _backWidthf;
    float           _backHeightf;
    float           _vertShiftf;

    float           _frontPerimf;
    float           _backPerimf;
};

#endif // YACONSTRAINTONE_H
