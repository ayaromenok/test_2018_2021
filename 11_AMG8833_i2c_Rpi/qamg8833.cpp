#include "qamg8833.h"
#include <QDebug>
#include <QTimer>

#include <wiringPiI2C.h>
#include <iostream>

QAMG8833::QAMG8833(QObject *parent) : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
    initI2C();
    initIR();
    dumpData();
    timer_ = new QTimer(this);
    connect (timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_->start(1000);
}

QAMG8833::~QAMG8833()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void
QAMG8833::update()
{
    qDebug() << __PRETTY_FUNCTION__;
    dumpData();
}

void
QAMG8833::run()
{
    qDebug() << __PRETTY_FUNCTION__;
    dumpData();
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
    rslt_ = wiringPiI2CWriteReg8(fd_, 0x02, 0x01);  	//set 10FPS
    qDebug() << "writing 0x02 reg" << rslt_;
    rslt_ = wiringPiI2CWriteReg8(fd_, 0x03, 0x00);	//disable interrups
    qDebug() << "writing 0x03 reg" << rslt_;

}

void
QAMG8833::dumpData()
{
    int raw, adr;
    QVector<float> rs;

    qDebug() << __PRETTY_FUNCTION__;
//    rslt_ = wiringPiI2CReadReg8(fd_, 0x0F);
    raw = (wiringPiI2CReadReg8(fd_, 0x0F) <<8) | wiringPiI2CReadReg8(fd_, 0x0E);
    qDebug() << "reading 0x0F/0x0E regs: sensor temp" << signed12bit2float(raw)*0.0625;
    
    for (int i=0; i<8; i++) {
	for (int j=0; j<8; j++) {
		adr = 0x80+(i*8+j)*2;
	        rslt_ = wiringPiI2CWriteReg8(fd_, adr, 0);
		rslt_ = wiringPiI2CReadReg16(fd_, adr);
		rs.append(signed12bit2float(rslt_)*0.25);
	}
    }
    qDebug() << "results:" << rs.length();

    for (int k=0; k<8; k++) {
	qDebug() << rs.at(k*8)<<"\t"<<rs.at(k*8+1)<<"\t"<<rs.at(k*8+2)<<"\t"<<rs.at(k*8+3)<<"\t"<<rs.at(k*8+4)<<"\t"<< rs.at(k*8+5)<<"\t"<< rs.at(k*8+6)<<"\t"<< rs.at(k*8+7); 
    }
//    rslt_ = wiringPiI2CWriteReg8(fd_, 0x80, 0);
//    qDebug() << "writing 0x80 reg" << rslt_;
//    rslt_ = wiringPiI2CReadReg16(fd_, 0x80);
//    qDebug() << "reading 0x80 reg" << rslt_;
//    qDebug() << "temp" << signed12bit2float(rslt_)*0.25;
}

float
QAMG8833::signed12bit2float(int value)
{
    //qDebug() << __PRETTY_FUNCTION__;

    int absValue = (value & 0x7FF);
    if (value & 0x8000){
	return (0-float(absValue));
    }
    return float(absValue);
}