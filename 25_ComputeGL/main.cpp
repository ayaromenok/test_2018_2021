#include <QtCore>
#include <QGuiApplication>
#include <QOpenGLContext>
#include <QSurfaceFormat>
#include "glwindow.h"



bool OGLSupports(int gles = false, int major = 2, int minor = 0){
    QOpenGLContext ctx;
    QSurfaceFormat fmt;
    int ctxMajor = 0;
    int ctxMinor = 0;
    bool isGles = false;

    fmt.setVersion(major, minor);
    if (gles) {
        fmt.setRenderableType(QSurfaceFormat::OpenGLES);
    } else {
        fmt.setRenderableType(QSurfaceFormat::OpenGL);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
    }
    ctx.setFormat(fmt);
    ctx.create();
    if(!ctx.isValid()){
        return false;
    }

    ctxMajor = ctx.format().majorVersion();
    ctxMinor = ctx.format().minorVersion();
    isGles = (ctx.format().renderableType() == QSurfaceFormat::OpenGLES);

    if (ctxMajor<major) return false;
    if (ctxMinor<minor) return false;
    if (isGles != gles) return false;

    return true;
}

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);

    if (OGLSupports(false,4,3)){
        qInfo("Requsting Desktop OpenGL 4.3 core context");
        fmt.setVersion(4,3);
        fmt.setRenderableType(QSurfaceFormat::OpenGL);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
    } else if (OGLSupports(true,3,1)){
        qInfo("Requsting OpenGL ES 3.1");
        fmt.setVersion(3,1);
        fmt.setRenderableType(QSurfaceFormat::OpenGLES);
    } else if ( OGLSupports(false,4,2)){
        qInfo("Requsting Desktop OpenGL 4.2 core context with ARB_Compute_shader");
        fmt.setVersion(4,2);
        fmt.setRenderableType(QSurfaceFormat::OpenGL);
        fmt.setProfile(QSurfaceFormat::CoreProfile);
        //we check ARB_compute_shader in GLWindow;
    } else {
        qErrnoWarning("no GL Context with Compute functionality, exiting..");
        return -1;
    }
    fmt.setSwapInterval(0); //VSync off
    QSurfaceFormat::setDefaultFormat(fmt);
    GLWindow w;

    w.setGeometry(100,100,480,240);
    w.show();

    return a.exec();
}
