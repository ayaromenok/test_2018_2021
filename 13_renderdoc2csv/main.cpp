#include <QCoreApplication>
#include <QtCore>
/* renderdoc transformed CSV
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

/*  renderdoc original CSV
    VTX,
    IDX,
    POSITION0.x, POSITION0.y, POSITION0.z,
    NORMAL0,
    TEXCOORD0.x, TEXCOORD0.y,
    TANGENT0, BINORMAL0,
    TEXCOORD4.x, TEXCOORD4.y, TEXCOORD4.z, TEXCOORD4.w,
    TEXCOORD5.x, TEXCOORD5.y, TEXCOORD5.z, TEXCOORD5.w,
    TEXCOORD6.x, TEXCOORD6.y, TEXCOORD6.z, TEXCOORD6.w,
    TEXCOORD7.x, TEXCOORD7.y, TEXCOORD7.z, TEXCOORD7.w
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
        if ( lsHeader.at(0).contains("VTX") &&
             lsHeader.at(1).contains("IDX") &&
             lsHeader.at(6).contains("TEXCOORD0.x")
             ) {
            QFile fileOut(QString(fName.left(fName.indexOf(".csv"))+".obj"));
            QFile fileOutMtl(QString(fName.left(fName.indexOf(".csv"))+".mtl"));

            if (lsHeader.at(2).contains("SV_Position.x")) {
               qInfo() << "file" << fName << "good RenderDoc/CSV tranformed model";
            } else {
              qInfo() << "file" << fName << "good RenderDoc/CSV orininal model";
            }


            while(tsIn.readLineInto(&line)) {
                QStringList list(line.simplified().split(", "));

                v.append(QString("v "+list.at(2)+" "+list.at(3)+" "+list.at(4) + "\n"));
                vt0.append(QString("vt "+list.at(6)+" "+list.at(7))+"\n");
            }
            file.close();

            if (fileOut.open(QFile::WriteOnly | QFile::Text)){
                QTextStream tsOut(&fileOut);
                tsOut << "# RenderDoc CSV 2 Obj\n\n";
                //tsOut << "g default\n";
                tsOut << "mtllib " << fileOutMtl.fileName() << "\n";
                tsOut << "o " << fName.left(fName.indexOf(".csv")) << "\n";
                tsOut << "# Vertecis\n";
                for (int i=0; i<v.length(); i++) {
                    tsOut << v.at(i);
                }
                tsOut << "\n# Texture Coorditanes 0\n";
                for (int i=0; i<vt0.length(); i++) {
                    tsOut << vt0.at(i);
                }
                tsOut << "usemtl " << "mtl" << fName.left(fName.indexOf(".csv")) << "\n";
                tsOut << "s off\n";
                tsOut << "\n# Faces\n";
                int fCount = v.length()/3;

                for (int i=0; i<fCount; i++){
                    tsOut << "f " << (i*3+1) << "/"  << (i*3+1) <<" "
                          << i*3+2 << "/" << i*3+2 << " "
                          << i*3+3 << "/" << i*3+3<<"\n";
                }
                tsOut.flush();
                fileOut.close();
            }

            if (fileOutMtl.open(QFile::WriteOnly | QFile::Text)){
                QTextStream tsOutMtl(&fileOutMtl);
                tsOutMtl << "# RenderDoc CSV 2 Obj/Mtl\n";
                tsOutMtl << "newmtl " << "mtl" << fName.left(fName.indexOf(".csv")) << "\n";
                tsOutMtl << "Ns 323.999994\n";
                tsOutMtl << "Ka 1.000000 1.000000 1.000000\n";
                tsOutMtl << "Kd 0.800000 0.800000 0.800000\n";
                tsOutMtl << "Ks 0.500000 0.500000 0.500000\n";
                tsOutMtl << "Ke 0.0 0.0 0.0\n";
                tsOutMtl << "Ni 1.450000\n";
                tsOutMtl << "d 1.000000\n";
                tsOutMtl << "illum 2\n";

                tsOutMtl.flush();
                fileOutMtl.close();
            }

        } else {
            qWarning() << "file" <<fName << "is not a RenderDoc/CSV, exiting...";
            exit(-4);
        }
    } else {
        qWarning() << "file" <<fName << "can't be open, exiting...";
        exit(-3);
    }

    return  result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (argc < 2) {
        qWarning() << "please provide a input file, exiting...";
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
