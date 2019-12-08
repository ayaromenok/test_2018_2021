//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "widget.h"
#include "yissue.h"
#include "yuser.h"
#include "yissuewidget.h"
#include "yissuedragwidget.h"
#include "yissuewidgetl.h"

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
    setGeometry(100, 100, 1024, 600);

    createUI();
    _lw = new QList<YIssueDragWidget*>;
    _lw->append(_ydwIn);
    _lw->append(_ydwToDo);
    _lw->append(_ydwDoing);
    _lw->append(_ydwDone);

    for (int i=0; i<3; i++){
        YIssueWidget *_iw = new YIssueWidget(_il->at(i), _ydwIn);
        _iw->setParentList(_lw);
        //_ydwIn->addIssue(_iw);
    }
    for (int i=3; i<_il->length(); i++){
        YIssueWidgetL *_iw = new YIssueWidgetL(_il->at(i)->title(), this);
        _ydwIn->addIssue(_iw);
    }

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

    _ydwIn = new YIssueDragWidget("In", this);
    _ydwToDo = new YIssueDragWidget("ToDo", this);
    _ydwDoing = new YIssueDragWidget("Doing", this);
    _ydwDone = new YIssueDragWidget("Done", this);

//    _ltIn = new QVBoxLayout(_gbIn);
//    _ltToDo = new QVBoxLayout(_gbToDo);
//    _ltDoing = new QVBoxLayout(_gbDoing);
//    _ltDone = new QVBoxLayout(_gbDone);

    _ltMain->addWidget(_ydwIn);
    _ltMain->addWidget(_ydwToDo);
    _ltMain->addWidget(_ydwDoing);
    _ltMain->addWidget(_ydwDone);
    setLayout(_ltMain);
}
