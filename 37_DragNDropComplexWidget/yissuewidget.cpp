//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>

#include "yissuewidget.h"
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
    _lbId = new QLabel(QString::number(_issue->id()));
    _lbTitle = new QLabel(_issue->title());
    _lbBody = new QLabel(_issue->body());

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

    setLayout(_ltMain);
}
