#include "glwindow.h"
#include "shaders.h"
#include <QtCore>
#include <QDebug>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>

GLWindow::GLWindow()
    :m_isExtHasCompute(true),
     m_isAnimationForward(true),
     m_blurCur(0.0f),
     m_blurMin(0.0f),
     m_blurMax(1.0f),
     m_blurStep(0.01f),
     m_fpsCounter(0)
{
    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateFPS()));
    m_Timer->start(1000);
    createGeom();
}

GLWindow::~GLWindow()
{
    m_Timer->stop();
}

void
GLWindow::updateFPS()
{
    qInfo() << "FPS:" << m_fpsCounter;
    m_fpsCounter = 0;
}

QByteArray
GLWindow::versionedShaderCode(const char *src)
{
    QByteArray versionedSrc;

    if (QOpenGLContext::currentContext()->isOpenGLES()){
        versionedSrc.append(QByteArrayLiteral("#version 310 es\n"));
    } else if (m_isExtHasCompute) {
        versionedSrc.append(QByteArrayLiteral("#version 420 core\n#extension ARB_compute_shader: enable\n"));
    } else {
        versionedSrc.append(QByteArrayLiteral("#version 430 core\n"));
    }

    versionedSrc.append(src);
    return versionedSrc;
}


void
GLWindow::initializeGL(){
    QOpenGLContext* ctx = QOpenGLContext::currentContext();
    if (ctx->isValid()){
        if ((ctx->format().majorVersion() == 4) & (ctx->format().minorVersion()==2)){
            if (!ctx->hasExtension("GL_ARB_compute_shader")){
                qErrnoWarning("Desktop GL 4.2 don't support Compute functionality, exiting..");
                return;
            } else {
                qInfo("Our last chance - GL_ARB_compute_shader on GL 4.2");
                m_isExtHasCompute = true;
            }
        } else {
            qInfo("GL with Compute functionality granted");
        }
    }
    connect(this,&QOpenGLWindow::frameSwapped,
            this, QOverload<>::of(&QOpenGLWindow::update));

    QImage img(":/res/512x512.png");
    if (img.isNull()){
        qErrnoWarning("test image missed, exiting..");
        return;
    } else {
        qInfo() << "test image " << img.width() <<"x" << img.height();
    }
    m_textImageInput = new QOpenGLTexture(img.convertToFormat(QImage::Format_RGBA8888).mirrored());

    m_shaderDisplay = new QOpenGLShaderProgram;
//    m_shaderDisplay->addShaderFromSourceFile(QOpenGLShader::Vertex,":/shaders/vertex.glsl");
//    m_shaderDisplay->addShaderFromSourceFile(QOpenGLShader::Fragment,":/shaders/fragment.glsl");
    m_shaderDisplay->addShaderFromSourceCode(QOpenGLShader::Vertex, versionedShaderCode(vsDisplaySource));
    m_shaderDisplay->addShaderFromSourceCode(QOpenGLShader::Fragment, versionedShaderCode(fsDisplaySource));
    m_shaderDisplay->link();
}


void
GLWindow::paintGL(){
    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    f->glClearColor(0, m_blurCur, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //f->glDispatchCompute(8,8,1); //no ARB prefix required fof ARB_compute_shader
    updateAnimParams();
}


void
GLWindow::updateAnimParams()
{
    if(m_isAnimationForward){
        m_blurCur += m_blurStep;
        if (m_blurCur>m_blurMax){
            m_isAnimationForward=false;
        }
    } else {
        m_blurCur -= m_blurStep;
        if (m_blurCur<(m_blurMin+m_blurStep)){
            m_isAnimationForward=true;
        }
    }
    m_fpsCounter++;
}

void
GLWindow::createGeom()
{
    m_data.resize(3*4);//quad
    float *p = m_data.data();

    *p++ = -1.0f;
    *p++ = -1.0f;
    *p++ = 10.0f;

    *p++ = -1.0f;
    *p++ = 1.0f;
    *p++ = 10.0f;

    *p++ = 1.0f;
    *p++ = 1.0f;
    *p++ = 10.0f;

    *p++ = 1.0f;
    *p++ = -1.0f;
    *p++ = 10.0f;
}
void
GLWindow::resizeGL(int w, int h){

}
