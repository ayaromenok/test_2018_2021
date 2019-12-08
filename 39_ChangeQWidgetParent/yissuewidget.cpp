//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuewidget.h"
#include "yissuedragwidget.h"
#include "yissue.h"

YIssueWidget::YIssueWidget(YIssue *issue, QWidget *parent) : QWidget(parent)
{
    if(issue){
        _issue = issue;
        setGeometry(0,0,256,80);
        setMaximumSize(256,80);
        createUI();
    } else {
        return;
    }
}

void
YIssueWidget::createUI()
{
    //! \todo make some visual test to find more robust issue view
    _lbId = new QLabel(QString::number(_issue->id()));
    _lbId->setFrameStyle(QFrame::Panel | QFrame::Raised);
    _lbId->setMaximumSize(30,30);
    _lbId->setMinimumSize(30,30);

    _lbTitle = new QLabel(_issue->title());
    _lbTitle->setFrameStyle(QFrame::Panel | QFrame::Raised);
    _lbTitle->setLineWidth(2);
    setObjectName(_issue->title());

    _lbBody = new QLabel(_issue->body());
    _lbBody->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    _lbBody->setMaximumSize(140,30);
    _lbBody->setMinimumSize(140,30);

    _fMain = new QFrame(this);

    _ltMain = new QVBoxLayout(this);
    _ltTopLine = new QHBoxLayout;
    _ltTopLine->addWidget(_lbId);
    _ltTopLine->addWidget(_lbTitle);

    _ltBody = new QHBoxLayout();
    _ltBody->addWidget(_lbBody);

    _ltBotLine = new QHBoxLayout();

    _ltMain->addLayout(_ltTopLine);
    _ltMain->addLayout(_ltBody);
    _ltMain->addLayout(_ltBotLine);

    _fMain->setLayout(_ltMain);
    //_fMain->setStyleSheet("background-color:darkgrey");
    _fMain->setFrameStyle(QFrame::Panel | QFrame::Raised);
}

void
YIssueWidget::setParentList(QList<YIssueDragWidget*> *lw)
{
    _lw = lw;
    if (_issue->id() == 3){
        qDebug() << "test issue >>>> " << objectName()
                 << "parent" << parent();
        setParent(_lw->at(1));
    }

}
