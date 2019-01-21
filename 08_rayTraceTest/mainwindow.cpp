#include "mainwindow.h"
#include<QtWidgets>

MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
    setUI();
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
    _pxmpImg = new QPixmap(128,96);
    _lbImg->setPixmap(*_pxmpImg);
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
