#include "widget.h"
#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _ltMain = new QVBoxLayout;
    _addFileDialog();
    _addColorDialog();
    setLayout(_ltMain);
    setGeometry(100,100,320,240);
    setWindowTitle(tr("010: QtWidget dialog tests"));
}

Widget::~Widget()
{

}

void
Widget::_addFileDialog()
{
    _bpDiagFile = new QPushButton(this);
    _dlFile = new QFileDialog(this, tr("File Dialog caption"), "~", "*.*");
    _bpDiagFile->setText(tr("QFileDialog"));
    _ltMain->addWidget(_bpDiagFile);

    connect(_bpDiagFile, SIGNAL(pressed()),
            _dlFile, SLOT(show()));
}

void
Widget::_addColorDialog()
{
    _bpDiagColor = new QPushButton(this);
//    QColor color =  QColor(Qt::red);
    _dlColor = new QColorDialog(this);
    _bpDiagColor->setText(tr("QColorDialog"));
    _ltMain->addWidget(_bpDiagColor);

    connect(_bpDiagColor, SIGNAL(pressed()),
            _dlColor, SLOT(show()));
}
