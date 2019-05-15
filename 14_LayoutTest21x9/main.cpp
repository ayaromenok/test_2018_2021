#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("Andrey Yaromenok");
    QApplication::setOrganizationDomain("andreyayromenok.info");
    QApplication::setApplicationName("LayoutTest21x9");
    QApplication::setApplicationVersion("0.1.0");

    MainWindow w;
    w.show();

    return a.exec();
}
