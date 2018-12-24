// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/test/blob/master/LICENSE

#include "mainwindow.h"
#include <QPainter>
MainWidget::MainWidget(QWidget *parent)
{
}

MainWidget::~MainWidget()
{

}

void
MainWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.drawEllipse(128,128,100,200);
}
