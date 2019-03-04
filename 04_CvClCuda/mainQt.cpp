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

    qDebug() << "04_QtCvClCuda";
    QTestObject qto;

    qto.testCPU(8, false, true);
    qto.testCL(8, false, true, true);
    qto.testCUDA(8, false, true);
    qto.testCPU(8, false, true);
    qto.testCL(8, false, true);
    qto.testCUDA(8, false, true);
    qto.testCPU(8, true, true);
    qto.testCL(8, true, true);
    qto.testCUDA(8, false, true);
    //qto.testCUDA();

    return 0;
    //return app.exec();
}
