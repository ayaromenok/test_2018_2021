#ifndef YACALENDARWIDGET_H
#define YACALENDARWIDGET_H

#include <QWidget>

class QGridLayout;
class QCalendarWidget;

class YaCalendarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YaCalendarWidget(QWidget *parent = nullptr);
    ~YaCalendarWidget();

signals:

public slots:

private:
    QGridLayout*        _layout;
    QCalendarWidget*    _calCur;
    QCalendarWidget*    _calNext;
};

#endif // YACALENDARWIDGET_H
