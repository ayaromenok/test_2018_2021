#include "mainwindow.h"
#include <QtWidgets>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
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
    _gboxImg->setMinimumSize(240,240);
    _gboxCtrl = new QGroupBox("control");
    _gboxCtrl->setMinimumSize(120,240);
    _lbImg = new QLabel("image");
    _imgImg = new QImage(128, 96, QImage::Format_RGB32);
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
    _imgImg->fill(Qt::darkCyan);
    _lbImg->setPixmap(QPixmap::fromImage(*_imgImg));
}
