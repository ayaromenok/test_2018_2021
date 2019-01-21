#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
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
};

#endif // MAINWINDOW_H
