#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
    _width = 320;
    _height = 240;
    setUI();
    testRT();
}

MainWindow::~MainWindow()
{

}

void
MainWindow::setUI()
{
    _loutHBox = new QHBoxLayout(this);
    _loutImg = new QVBoxLayout();
    _loutCtrl = new QVBoxLayout();
    _gboxImg = new QGroupBox("image");
    _gboxImg->setMinimumSize(_width+10,_height+10);
    _gboxCtrl = new QGroupBox("control");
    _gboxCtrl->setMinimumSize(120,_height+10);
    _lbImg = new QLabel("image");
    _imgImg = new QImage(_width, _height, QImage::Format_RGB32);
    _imgImg->fill(Qt::lightGray);
    _lbImg->setPixmap(QPixmap::fromImage(*_imgImg));
    _lbCtrl = new QLabel("control");
    _lbCtrlNext = new QLabel("control next");

    _loutImg->addWidget(_lbImg);
    _loutCtrl->addWidget(_lbCtrl);
    _loutCtrl->addWidget(_lbCtrlNext);

    _gboxImg->setLayout(_loutImg);
    _gboxCtrl->setLayout(_loutCtrl);

    _loutHBox->addWidget(_gboxImg);
    _loutHBox->addWidget(_gboxCtrl);

    this->setLayout(_loutHBox);
}

void
MainWindow::testRT()
{
    //_imgImg->fill(Qt::darkCyan);
    const RtSphere sphere(QVector3D(1,0,-10), 3);
    const int fov      = M_PI/2.;

    for (int i=0; i<_width; i++){
        for (int j=0; j<_height; j++){
            float x =  (2*(i + 0.5)/(float)_width  - 1)*tan(fov/2.)*_width/(float)_height;
            float y = -(2*(j + 0.5)/(float)_height - 1)*tan(fov/2.);
            QVector3D dir = QVector3D(x, y, -1).normalized();
            _imgImg->setPixelColor(i, j, castRay(QVector3D(0,0,0), dir, sphere));
        }
    }
    _lbImg->setPixmap(QPixmap::fromImage(*_imgImg));
}


QColor
MainWindow::castRay(const QVector3D &origin, const QVector3D &direction,
                  const RtSphere &sphere)
{
    float maxDist = std::numeric_limits<float>::max();
    if (sphere.rayIntersect(origin, direction, maxDist)){
        return QColor::fromRgbF(1.0,0,0);
    }
    return QColor::fromRgbF(0.25, 0.25, 0.25);
}
