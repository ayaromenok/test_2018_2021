#include "yacalendarwidget.h"
#include <QGridLayout>
#include <QCalendarWidget>

YaCalendarWidget::YaCalendarWidget(QWidget *parent) : QWidget(parent)
{
    _layout = new QGridLayout();
    _calCur = new QCalendarWidget();
    _calNext = new QCalendarWidget();
    _layout->addWidget(_calCur, 0, 0);
    _layout->addWidget(_calNext, 1, 0);
    setLayout(_layout);
}

YaCalendarWidget::~YaCalendarWidget()
{

}
