#include <QCoreApplication>
#include <QtCore>
#include <QtNetwork>
#include "yrestapiprj.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "gitHub POST API test" ;

    YRestApiPrj testRAP;

    return a.exec();
}
