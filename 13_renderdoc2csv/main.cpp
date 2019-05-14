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
    QStringList vt0;
    QStringList f;

    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream     tsIn(&file);
        QString         line;

        tsIn.readLineInto(&line);
        //sometime dual space used to separarte values, so remove it first
        QStringList lsHeader(line.simplified().split(" "));
        if (lsHeader.at(0).contains("VTX") && lsHeader.at(1).contains("IDX") &&
                lsHeader.at(2).contains("SV_Position.x")
                && lsHeader.at(6).contains("TEXCOORD0.x")) {
            QFile fileOut(QString(fName.left(fName.indexOf(".csv"))+".obj"));

            qInfo() << "file" << fName << "good RenderDoc/CSV file";
            while(tsIn.readLineInto(&line)) {
                QStringList list(line.simplified().split(", "));

                v.append(QString("v "+list.at(2)+" "+list.at(3)+" "+list.at(4) + "\n"));
                vt0.append(QString("vt "+list.at(6)+" "+list.at(7))+"\n");


//                for (int i=0; i<list.length();++i) {
//                    qInfo() << i << list.at(i) << list.at(i).toLocal8Bit().constData();
//                }
            }
            file.close();

            if (fileOut.open(QFile::WriteOnly | QFile::Text)){
                QTextStream tsOut(&fileOut);
                tsOut << "#RenderDoc CSV 2 Obj\n";
                tsOut << "#Vertecis\n\n";
                for (int i=0; i<v.length(); i++) {
                    tsOut << v.at(i);
                }
                tsOut << "#Texture Coorditanes 0\n\n";
                for (int i=0; i<vt0.length(); i++) {
                    tsOut << vt0.at(i);
                }
                tsOut << "#Faces\n\n";
                int fCount = v.length()/3;
                for (int i=0; i<fCount; i++){
                    tsOut << "f " << i*3+1 << "/" << i*3+2 << "/" << i*3+3 << "\n";
                }
                tsOut.flush();
                fileOut.close();
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
