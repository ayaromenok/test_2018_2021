#include "mainwindow.h"
#include <QCalendarWidget>
#include <QGridLayout>
#include "yacalendarwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGridLayout *layout = new QGridLayout;
    YaCalendarWidget *cal = new YaCalendarWidget;
    layout->addWidget(cal, 0, 0);
    this->setCentralWidget(cal);

    this->setWindowTitle("Calendar/Widget");
}

MainWindow::~MainWindow()
{

}
