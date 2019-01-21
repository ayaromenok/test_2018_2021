#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <rtsphere.h>

class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;
class QLabel;
class QPixmap;
class QImage;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QColor castRay(const QVector3D &origin, const QVector3D &direction,
                      const RtSphere &sphere);

private:
    void            setUI();
    void            testRT();
    QHBoxLayout     *_loutHBox;
    QGroupBox       *_gboxImg;
    QGroupBox       *_gboxCtrl;
    QVBoxLayout     *_loutImg;
    QVBoxLayout     *_loutCtrl;
    QLabel          *_lbImg;
    QLabel          *_lbCtrl;
    QLabel          *_lbCtrlNext;
    QImage          *_imgImg;
    int             _width;
    int             _height;
};

#endif // MAINWINDOW_H
