//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEWIDGET_H
#define YISSUEWIDGET_H

#include <QWidget>
class YIssue;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QFrame;
class YIssueDragWidget;

class YIssueWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YIssueWidget(YIssue *issue, QWidget *parent = nullptr);
    void setParentList(QList<YIssueDragWidget*> *lw);

signals:

private:
    void createUI();
    YIssue      *_issue;
    QVBoxLayout *_ltMain;
    QHBoxLayout *_ltTopLine;
    QHBoxLayout *_ltBody;
    QHBoxLayout *_ltBotLine;
    QFrame      *_fMain;
    QLabel      *_lbId;
    QLabel      *_lbTitle;
    QLabel      *_lbBody;
    QList<YIssueDragWidget*> *_lw;

};

#endif // YISSUEWIDGET_H
