#include "glwindow.h"
#include "shaders.h"
#include <QtCore>
#include <QDebug>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

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
    m_texImageInput = new QOpenGLTexture(img.convertToFormat(QImage::Format_RGBA8888).mirrored());

    m_shaderDisplay = new QOpenGLShaderProgram;
    m_shaderDisplay->addShaderFromSourceCode(QOpenGLShader::Vertex, versionedShaderCode(vsDisplaySource));
    m_shaderDisplay->addShaderFromSourceCode(QOpenGLShader::Fragment, versionedShaderCode(fsDisplaySource));
    m_shaderDisplay->link();

    // Create a VAO. Not strictly required for ES 3, but it is for plain OpenGL core context.
    m_vao = new QOpenGLVertexArrayObject;
    m_vao->create();
}


void
GLWindow::paintGL(){
    QOpenGLExtraFunctions *f = QOpenGLContext::currentContext()->extraFunctions();

    f->glClearColor(0, m_blurCur, 0, 1);
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //f->glDispatchCompute(8,8,1); //no ARB prefix required fof ARB_compute_shader
    updateAnimParams();

    m_shaderDisplay->bind();
    m_shaderDisplay->setUniformValue("matProjection",m_proj);
    //m_shaderDisplay->setUniformValue("imageRatio",m_quadSize);
    m_shaderDisplay->setUniformValue("samImage",0);
    m_vao->bind();
    f->glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    m_vao->release();
    m_shaderDisplay->release();
}

void computeProjection(int winWidth, int winHeight, int imgWidth, int imgHeight, QMatrix4x4 &outProjection, QSizeF &outQuadSize)
{
    float ratioImg    = float(imgWidth) / float(imgHeight);
    float ratioCanvas = float(winWidth) / float(winHeight);

    float correction    = ratioImg / ratioCanvas;
    float rescaleFactor = 1.0f;
    float quadWidth     = 1.0f;
    float quadHeight    = 1.0f;

    if (correction < 1.0f)  // canvas larger than image -- height = 1.0, vertical black bands
    {
        quadHeight     = 1.0f;
        quadWidth    = 1.0f * ratioImg;
        rescaleFactor = ratioCanvas;
        correction    = 1.0f / rescaleFactor;
    }
    else                    // image larger than canvas -- width = 1.0, horizontal black bands
    {
        quadWidth  = 1.0f;
        quadHeight = 1.0f / ratioImg;
        correction = 1.0f / ratioCanvas;
    }

    const float frustumWidth  = 1.0f * rescaleFactor;
    const float frustumHeight = 1.0f * rescaleFactor * correction;

    outProjection = QMatrix4x4();
    outProjection.ortho(
        -frustumWidth,
         frustumWidth,
        -frustumHeight,
         frustumHeight,
        -1.0f,
         1.0f);
    outQuadSize = QSizeF(quadWidth,quadHeight);
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
GLWindow::resizeGL(int w, int h){
    computeProjection(w,h,m_texImageInput->width(),m_texImageInput->height(),m_proj,m_quadSize);
}