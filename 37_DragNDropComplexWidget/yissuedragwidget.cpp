//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>
#include "yissuedragwidget.h"
#include "yissuewidget.h"

YIssueDragWidget::YIssueDragWidget(const QString &title, QWidget *parent) :
    QWidget(parent)
{
    _title = title;
    createUI();
    setAcceptDrops(true);
}

void
YIssueDragWidget::createUI()
{
    _fMain = new QFrame(this);
    _ltMain = new QVBoxLayout(this);
    _lbTitle = new QLabel(_title, this);
    _ltMain->addWidget(_lbTitle);
}

void
YIssueDragWidget::addIssue(YIssueWidget *issue)
{
    _ltMain->addWidget(issue);
}
