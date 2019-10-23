#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWindow>

class GLWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    GLWindow();
    ~GLWindow();

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

private:
    bool        m_isCoreHasCompute;
};
#endif // GLWINDOW_H
