//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEWIDGET_H
#define YISSUEWIDGET_H

#include <QWidget>
class YIssue;
class QVBoxLayout;
class QHBoxLayout;
class QLabel;

class YIssueWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YIssueWidget(YIssue *issue, QWidget *parent = nullptr);

signals:

private:
    void createUI();
    YIssue      *_issue;
    QVBoxLayout *_ltMain;
    QHBoxLayout *_ltTopLine;
    QHBoxLayout *_ltBody;
    QHBoxLayout *_ltBotLine;
    QLabel      *_lbId;
    QLabel      *_lbTitle;
    QLabel      *_lbBody;

};

#endif // YISSUEWIDGET_H
