#include <QCoreApplication>
#include "qamg8822.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QAMG8822 ir;

    ir.initI2C();
    ir.initIR();
    ir.dumpData();

    return a.exec();
}
