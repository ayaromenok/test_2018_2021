//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class YIssue;
class YUser;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    QList<YIssue*>  *_il;
    QList<YUser*>   *_ul;
};
#endif // WIDGET_H
