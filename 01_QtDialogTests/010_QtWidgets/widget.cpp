#include "widget.h"
#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _ltMain = new QVBoxLayout;
    _addFileDialog();
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
    _bpDiagFile->setText(tr("Dialog 00"));
    _ltMain->addWidget(_bpDiagFile);

    connect(_bpDiagFile, SIGNAL(pressed()),
            _dlFile, SLOT(show()));
}
