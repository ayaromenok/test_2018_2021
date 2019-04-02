#include "qamg8833.h"
#include <QDebug>

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
