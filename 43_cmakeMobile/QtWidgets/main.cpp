//Copyrigth (C) 2019 Andrey Yaromenok
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    MainWindow w;
    w.show();
    return a.exec();
}
