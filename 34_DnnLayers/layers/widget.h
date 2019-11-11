//Copyrigth (C) 2019 Andrey Yaromenok
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QLabel;
class QImage;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    void initUI();
    QLabel* _lbIn;
    QLabel* _lbTmp;
    QLabel* _lbOut;
    QImage* _imgIn;
    QImage* _imgTmp;
    QImage* _imgOut;
};
#endif // WIDGET_H
