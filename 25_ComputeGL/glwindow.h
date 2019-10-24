#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWindow>
#include <QMatrix4x4>

QT_BEGIN_NAMESPACE
class QTimer;
class QOpenGLTexture;
class QOpenGLShaderProgram;
class QOpenGLVertexArrayObject;
QT_END_NAMESPACE

class GLWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    GLWindow();
    ~GLWindow();

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private slots:
    void updateFPS();

private:
    void updateAnimParams();
    QByteArray versionedShaderCode(const char *src);

    bool        m_isExtHasCompute;
    bool        m_isAnimationForward;
    float       m_blurCur;
    float       m_blurMin;
    float       m_blurMax;
    float       m_blurStep;
    quint32     m_fpsCounter;
    QMatrix4x4  m_proj;
    QSizeF      m_quadSize;

    QTimer                  *m_Timer;

    QOpenGLTexture          *m_texImageInput;
    //QOpenGLTexture          *m_texImageTmp;
    //QOpenGLTexture          *m_texImageProcessed;

    QOpenGLShaderProgram *m_shaderDisplay;
    //QOpenGLShaderProgram *m_shaderComputeV;
    //QOpenGLShaderProgram *m_shaderComputeH;

    QOpenGLVertexArrayObject *m_vao;


};
#endif // GLWINDOW_H
