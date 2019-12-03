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
    createUI();
}

Widget::~Widget()
{
    _il->clear();
    delete _il;
    _ul->clear();
    delete _ul;
}

void
Widget::createUI()
{
    _ltMain = new QHBoxLayout(this);

    _gbIn = new QGroupBox("In", this);
    _gbToDo = new QGroupBox("ToDo", this);
    _gbDoing = new QGroupBox("Doing", this);
    _gbDone = new QGroupBox("Done", this);

    _ltIn = new QVBoxLayout(_gbIn);
    _ltToDo = new QVBoxLayout(_gbToDo);
    _ltDoing = new QVBoxLayout(_gbDoing);
    _ltDone = new QVBoxLayout(_gbDone);

    _ltMain->addWidget(_gbIn);
    _ltMain->addWidget(_gbToDo);
    _ltMain->addWidget(_gbDoing);
    _ltMain->addWidget(_gbDone);
    setLayout(_ltMain);
}
