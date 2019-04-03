#include "qamg8833.h"
#include <QDebug>

#include <wiringPiI2C.h>
#include <iostream>

QAMG8833::QAMG8833(QObject *parent) : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QAMG8833::~QAMG8833()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void
QAMG8833::initI2C(int AMG8833)
{
    qDebug() << __PRETTY_FUNCTION__;

    qDebug() << "AMG8833 i2c address" << AMG8833;
    fd_ = wiringPiI2CSetup(0x69);
    qDebug() << "init result" << fd_;

}

void
QAMG8833::initIR()
{
    qDebug() << __PRETTY_FUNCTION__;
    rslt_ = wiringPiI2CWriteReg8(fd_, 0x00, 0x00);  	//set NORMAL_MODE
    qDebug() << "writing 0x00 reg" << rslt_;
    rslt_ = wiringPiI2CWriteReg8(fd_, 0x01, 0x3F);	//INITIAL_RESET
    qDebug() << "writing 0x01 reg" << rslt_;
    rslt_ = wiringPiI2CWriteReg8(fd_, 0x02, 0x00);  	//set 10FPS
    qDebug() << "writing 0x02 reg" << rslt_;

}

void
QAMG8833::dumpData()
{
    qDebug() << __PRETTY_FUNCTION__;
    rslt_ = wiringPiI2CReadReg8(fd_, 0x0F);
    qDebug() << "reading 0x0F reg" << signed12bit2float(rslt_);

}

float
QAMG8833::signed12bit2float(int value)
{
    qDebug() << __PRETTY_FUNCTION__;

    int absValue = (value & 0x7FF);
    if (value & 0x8000){
	return (0-float(absValue));
    }
    return float(absValue);
}