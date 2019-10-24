#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWindow>

QT_BEGIN_NAMESPACE
class QTimer;
class QOpenGLTexture;
class QOpenGLShaderProgram;
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
    void createGeom();

    bool        m_isCoreHasCompute;
    bool        m_isAnimationForward;
    float       m_blurCur;
    float       m_blurMin;
    float       m_blurMax;
    float       m_blurStep;
    quint32     m_fpsCounter;

    QTimer                  *m_Timer;

    QOpenGLTexture          *m_textImageInput;
    //QOpenGLTexture          *m_textImageTmp;
    //QOpenGLTexture          *m_textImageProcessed;

    QOpenGLShaderProgram *m_shaderDisplay;
    //QOpenGLShaderProgram *m_shaderComputeV;
    //QOpenGLShaderProgram *m_shaderComputeH;

    QVector<float>      m_data;
    quint32             m_count;

};
#endif // GLWINDOW_H
