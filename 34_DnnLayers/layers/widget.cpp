//Copyrigth (C) 2019 Andrey Yaromenok
#include "widget.h"
#include <QtCore>
#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    initUI();
}

Widget::~Widget()
{
}

void
Widget::initUI()
{
    QHBoxLayout* hl = new QHBoxLayout;
    _lbIn = new QLabel("lbIn");
    _lbTmp = new QLabel("lbTmp");
    _lbOut = new QLabel("lbOut");
    _imgIn = new QImage();
    _imgTmp = new QImage();
    _imgOut = new QImage();

    //todo - scale images, move them to qt resources
    _imgIn->load("../../../34_DnnLayers/data.small/train/cats/cat.0.jpg");
    if (_imgIn->depth() >0) {
        qInfo() << "image" << _imgIn->width() << "x" << _imgIn->height();
    } else {
        qErrnoWarning("can't load image");
        return;
    }
    _lbIn->setPixmap(QPixmap::fromImage(*_imgIn));
    hl->addWidget(_lbIn);
    hl->addWidget(_lbTmp);
    hl->addWidget(_lbOut);
    this->setLayout(hl);
}

