#include "glwindow.h"
#include <QDebug>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>

GLWindow::GLWindow()
    :m_isCoreHasCompute(true)
{

}

GLWindow::~GLWindow()
{
}

void
GLWindow::initializeGL(){
    QOpenGLContext* ctx = QOpenGLContext::currentContext();
    if (ctx->isValid()){
        if (!ctx->hasExtension("GL_ARB_compute_shader")){
            qErrnoWarning("Desktop GL 4.2 don't support Compute functionality, exiting..");
            return;
        } else {
            qInfo("Our last chance - GL_ARB_compute_shader");
            m_isCoreHasCompute = false;
        }
    }
}
void
GLWindow::paintGL(){
    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    f->glClearColor(0, 0.5, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //f->glDispatchCompute(8,8,1); //no ARB prefix required fof ARB_compute_shader
}
void
GLWindow::resizeGL(int w, int h){

}
