#include <QCoreApplication>
#include <QDebug>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl31.h>
#include <fcntl.h>
#include <gbm.h>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int32_t fd = open ("/dev/dri/renderD128", O_RDWR);
    qDebug() << "fd" << fd;

    return a.exec();
}
