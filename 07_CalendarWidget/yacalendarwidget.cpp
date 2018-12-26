#include "yacalendarwidget.h"
#include <QGridLayout>
#include <QCalendarWidget>
#include <QGroupBox>
#include <QDateEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDate>
#include <QDebug>

YaCalendarWidget::YaCalendarWidget(QWidget *parent) : QWidget(parent)
{
    _layout = new QGridLayout();
    _calCur = new QCalendarWidget();
    _calNext = new QCalendarWidget();
    _layout->addWidget(_calCur, 0, 0);
    //_layout->addWidget(_calNext, 1, 0);
    _dates = new QVector<QDate>;
    _gbDates = new QGroupBox();

    QDateEdit* deOneStart = new QDateEdit();
    QDate date = QDate::currentDate();
    deOneStart->setDate(date);
    deOneStart->setDisplayFormat("yyyy.MM.dd");
    deOneStart->setCalendarPopup(true);
    deOneStart->setCalendarWidget(_calNext);

    _dates->append(date);

    QDateEdit* deOneEnd = new QDateEdit(QDate(2018,12,28));
    deOneEnd->setDisplayFormat("yyyy.MM.dd");
    QHBoxLayout* hbOne = new QHBoxLayout;
    hbOne->addWidget(deOneStart);
    hbOne->addWidget(deOneEnd);

    _gbDates->setLayout(hbOne);

    _layout->addWidget(_gbDates, 1, 0);
    setLayout(_layout);
    qDebug() << "dates" << _dates->toList();
}

YaCalendarWidget::~YaCalendarWidget()
{

}
