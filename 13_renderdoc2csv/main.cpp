#include <QCoreApplication>
#include <QtCore>
/*
 * VTX,
 * IDX,
 * SV_Position.x, SV_Position.y, SV_Position.z, SV_Position.w,
 * TEXCOORD0.x, TEXCOORD0.y, TEXCOORD4,
 * TEXCOORD1.x, TEXCOORD1.y, TEXCOORD1.z,
 * TEXCOORD2.x, TEXCOORD2.y, TEXCOORD2.z,
 * TEXCOORD3.x, TEXCOORD3.y, TEXCOORD3.z,
 * TEXCOORD5.x, TEXCOORD5.y, TEXCOORD5.z, TEXCOORD5.w,
 * TEXCOORD6.x, TEXCOORD6.y, TEXCOORD6.z, TEXCOORD6.w,
 * TEXCOORD7.x, TEXCOORD7.y, TEXCOORD7.z,
 * TEXCOORD8.x, TEXCOORD8.y, TEXCOORD8.z, TEXCOORD8.w
 */
bool parseRdCsv(QString &fName)
{
    qInfo() << __PRETTY_FUNCTION__ << fName;
    bool    result = false;
    QFile file(fName);
    QStringList v;
    QStringList vt;
    QStringList f;

    if (file.open(QIODevice::ReadOnly |QIODevice::Text)) {
        QTextStream     tsIn(&file);
        QString         line;

        tsIn.readLineInto(&line);
        //sometime dual space used to separarte values, so remove it first
        QStringList lsHeader(line.simplified().split(" "));
        if (lsHeader.at(0).contains("VTX") && lsHeader.at(1).contains("IDX") &&
                lsHeader.at(2).contains("SV_Position.x")
                && lsHeader.at(6).contains("TEXCOORD0.x")) {
            qInfo() << "file" << fName << "good RenderDoc/CSV file";
            while(tsIn.readLineInto(&line)) {
                QStringList list(line.simplified().split(", "));

                for (int i=0; i<list.length();++i) {
                    qInfo() << i << list.at(i) << list.at(i).toLocal8Bit().constData();
                }
            }
        } else {
            qWarning() << "file" <<fName << "is not a RenderDoc/CSV, exiting...";
            exit(-4);
        }
    } else {
        qWarning() << "file" <<fName << "cant be open, exiting...";
        exit(-3);
    }

    return  result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2) {
        qWarning() << "please provide a input file, exitin";
        exit(-1);
    }

    if (2 == argc){
        QString fName(argv[1]);
        QFileInfo fi(fName);
        if (fi.exists()) {
            qInfo() << "file" << fName << "with size" << fi.size() << "bytes";
            parseRdCsv(fName);
        } else {
            qWarning() << "input file don't exist, exiting...";
            exit (-2);
        }
    }

    exit(0);
}
