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

    rslt_ = wiringPiI2CWriteReg8(fd_, 0x00, 0x00);
    qDebug() << "writing 0x00 reg" << rslt_;
}

void
QAMG8833::initIR()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void
QAMG8833::dumpData()
{
    qDebug() << __PRETTY_FUNCTION__;
}
