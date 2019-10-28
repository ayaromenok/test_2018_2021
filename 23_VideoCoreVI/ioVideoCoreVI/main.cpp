#include <QCoreApplication>
#include <QDebug>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "access VideoCoreVI";

    FILE * fp;
    fp = fopen("/dev/dri/card0", "r+");


    fclose(fp);
    return a.exec();
}
