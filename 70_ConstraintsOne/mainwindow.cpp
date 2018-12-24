// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#include "mainwindow.h"
#include <QPainter>
#include "yaconstraintone.h"

MainWidget::MainWidget(QWidget *parent)
{
    _fs = new YaConstraintOne();

}

MainWidget::~MainWidget()
{
    delete _fs;
}

void
MainWidget::paintEvent(QPaintEvent *)
{

    float fWidth = 44.27;//58.746;//
    float fHeight = 44.27;//58.746;//4.427
    float bWidth = 29.373;
    float bHeight = 29.373;
    float length = 50;

    _fs->setParams(length, fWidth, fHeight, bWidth, bHeight);

    QPainter painter(this);

    painter.setPen(Qt::black);
    painter.drawEllipse(150, 50, fWidth, fHeight);
    painter.drawEllipse(250, 50, bWidth, bHeight);

    painter.setFont(QFont("Arial", 10));
    painter.drawText(5,15, "front width:");
    painter.drawText(80,15, QString::number(fWidth));
    painter.drawText(5,30, "front height:");
    painter.drawText(80,30, QString::number(fHeight));
    painter.drawText(5,45, "back width:");
    painter.drawText(80,45, QString::number(bWidth));
    painter.drawText(5,60, "back height:");
    painter.drawText(80,60, QString::number(bHeight));
    painter.drawText(5,75, "length:");
    painter.drawText(80,75, QString::number(length));

    painter.setPen(Qt::blue);
    painter.drawText(5,150, "front perim:");
    painter.drawText(80,150, QString::number(_fs->getFrontPerimeter()));
    painter.drawText(5,165, "back perim:");
    painter.drawText(80,165, QString::number(_fs->getBackPerimeter()));
    painter.drawText(5,180, "conus point:");
    painter.drawText(80,180, QString::number(_fs->getConusTopPoint()));
    painter.drawText(5,195, "conus angle:");
    painter.drawText(80,195, QString::number(_fs->getConusAngle()));

    painter.drawLine(150, 150, (150+_fs->getFrontPerimeter()), 150);
    painter.drawLine(150, (150+length), (150+_fs->getBackPerimeter()), (150+length));


    painter.setPen(Qt::green);
    //painter.drawLine(300, 150, 300, 150+_fs->getConusTopPoint());
    float ctp = _fs->getConusTopPoint();
    float ctpl = ctp - length;
    float ca = _fs->getConusAngle();
    painter.drawArc(300,150,ctp*2,ctp*2,
                    (90-ca/2)*16, ca*16);

    painter.drawArc(300+length,150+length,ctpl*2,ctpl*2,
                    (90-ca/2)*16, ca*16);
}
