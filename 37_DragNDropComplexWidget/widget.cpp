//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "widget.h"
#include "yissue.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _il = new QList<YIssue*>;
    for (int i=1; i<6; i++){
        YIssue *is = new YIssue(this);
        is->setId(i);
        is->setIid(i*8+1000);
        is->setTitle("Issue #" + QString::number(i));
        is->setBody("body of issue #" + QString::number(i));
        is->setUser(127);
        _il->append(is);
    }
}

Widget::~Widget()
{
    _il->clear();
    delete _il;
}

