//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "widget.h"
#include "yissue.h"
#include "yuser.h"

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
        is->setUser(i==2?2:1);
        _il->append(is);
    }

    _ul = new QList<YUser*>;
    for (int i=1; i<3; i++){
        YUser *user = new YUser(this);
        user->setId(i);
        user->setUserName("userName №"+QString::number(i));
        _ul->append(user);
    }
}

Widget::~Widget()
{
    _il->clear();
    delete _il;
    _ul->clear();
    delete _ul;
}

