// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include "qtestobject.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    qDebug() << "QtCvClCuda";
    NqTestObject to;

    to.getClInfo();
    to.testCPU();
    to.testCL();
    to.testCPU();
    to.testCL();
    to.testCPU();
    to.testCL();
    to.testCUDA();

    return app.exec();
}
