#include <QCoreApplication>
#include <QDebug>
#include <QtCore>

//! ags should be send as a separate strings in stringlist:
//! i.e.: <<"branch" << "-a" instead of "branch -a"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QProcess ps;
    QProcessEnvironment env =  QProcessEnvironment::systemEnvironment();
    env.insert("WORKDIR", "/tmp");
    QStringList args("branch");
    args << "-a";


    ps.setProgram("git");
    ps.setProcessEnvironment(env);
    ps.setArguments(args);
    ps.start();
    ps.waitForFinished(-1);

    QString sStdOut = ps.readAllStandardOutput();
    QString sStdErr = ps.readAllStandardError();

    qDebug() << "result" << sStdOut << sStdErr;

    return a.exec();
}
