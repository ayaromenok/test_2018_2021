//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class YIssue;
class YUser;
class QHBoxLayout;
class QVBoxLayout;
class QGroupBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    void createUI();
    QList<YIssue*>  *_il;
    QList<YUser*>   *_ul;
    QHBoxLayout     *_ltMain;
    QVBoxLayout     *_ltIn;
    QVBoxLayout     *_ltToDo;
    QVBoxLayout     *_ltDoing;
    QVBoxLayout     *_ltDone;
    QGroupBox       *_gbIn;
    QGroupBox       *_gbToDo;
    QGroupBox       *_gbDoing;
    QGroupBox       *_gbDone;

};
#endif // WIDGET_H
