#ifndef YACALENDARWIDGET_H
#define YACALENDARWIDGET_H

#include <QWidget>

class QGridLayout;
class QCalendarWidget;
class QDate;
class QGroupBox;

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
    QVector<QDate>*     _dates;
    QGroupBox*          _gbDates;
};

#endif // YACALENDARWIDGET_H
