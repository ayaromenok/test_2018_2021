//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuewidgetl.h"

YIssueWidgetL::YIssueWidgetL(const QString &text, QWidget *parent)
{
    const QSize size(252,80);
    setText(text);
    setObjectName(text);
    //setFrameStyle(QFrame::Panel | QFrame::Raised);
    setGeometry(0, 0, size.width(), size.height());
    setMaximumSize(size);
    setMinimumSize(size);
    //setStyleSheet("background-color:darkgrey");
    QImage image(size,QImage::Format_ARGB32_Premultiplied);
    image.fill(qRgba(64,64,64,0));

    QPainter painter;
    painter.begin(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::lightGray);
    painter.drawRect(0, 0, size.width()-1, size.height()-1);
    painter.setBrush(Qt::black);
    painter.drawText(20, 20, text);
    painter.end();
    setPixmap(QPixmap::fromImage(image));

}
