//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef YISSUEDRAGWIDGET_H
#define YISSUEDRAGWIDGET_H

#include <QWidget>
class QFrame;
class QLabel;
class QVBoxLayout;
class YIssueWidget;

class YIssueDragWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YIssueDragWidget(const QString &title, QWidget *parent = nullptr);
    void addIssue(YIssueWidget *issue);

signals:

private:
    void createUI();
    QFrame          *_fMain;
    QVBoxLayout     *_ltMain;
    QLabel          *_lbTitle;
    QString         _title;
};

#endif // YISSUEDRAGWIDGET_H
