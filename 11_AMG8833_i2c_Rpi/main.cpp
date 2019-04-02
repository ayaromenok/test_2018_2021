#include <QCoreApplication>
#include "qamg8833.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QAMG8833 ir;

    ir.initI2C();
    ir.initIR();
    ir.dumpData();

    return a.exec();
}
