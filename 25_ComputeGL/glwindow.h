#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWindow>

class QTimer;

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

    bool        m_isCoreHasCompute;
    bool        m_isAnimationForward;
    float       m_blurCur;
    float       m_blurMin;
    float       m_blurMax;
    float       m_blurStep;
    QTimer*     m_Timer;
    quint32     m_fpsCounter;
};
#endif // GLWINDOW_H
