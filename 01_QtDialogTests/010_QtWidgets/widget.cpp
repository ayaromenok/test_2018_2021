#include "widget.h"
#include <QtWidgets>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _layoutMain = new QVBoxLayout(this);
    _addFileDialog();
    _addColorDialog();
    _addErrorDialog();
    _addFontDialog();
    setLayout(_layoutMain);
    setGeometry(100,100,320,240);
    setWindowTitle(tr("010: QtWidget dialog tests"));
}

Widget::~Widget()
{

}

void
Widget::_addFileDialog()
{
    _btpFileDialog = new QPushButton(this);
    _dlgFile = new QFileDialog(this, tr("File Dialog caption"), "~", "*.*");
    _btpFileDialog->setText(tr("QFileDialog"));
    _layoutMain->addWidget(_btpFileDialog);

    connect(_btpFileDialog, SIGNAL(pressed()),
            _dlgFile, SLOT(show()));
}

void
Widget::_addColorDialog()
{
    _btpColorDialog = new QPushButton(this);
    _dlgColor = new QColorDialog(this);
    _btpColorDialog->setText(tr("QColorDialog"));
    _layoutMain->addWidget(_btpColorDialog);

    connect(_btpColorDialog, SIGNAL(pressed()),
            _dlgColor, SLOT(show()));
}

void
Widget::_addErrorDialog()
{
    _btpErrorDialog = new QPushButton(this);
    _dlgError = new QErrorMessage(this);
    _btpErrorDialog->setText(tr("QErrorMessage"));
    _layoutMain->addWidget(_btpErrorDialog);
    //_dlgError->showMessage("Error messags");
    connect(_btpErrorDialog, SIGNAL(pressed()),
            _dlgError, SLOT(show()));
}

void
Widget::_addFontDialog()
{
    _btpFontDialog = new QPushButton(this);
    _dlgFont = new QFontDialog(this);
    //_dlgFont->setOption(QFontDialog::DontUseNativeDialog); for OSX only
    _btpFontDialog->setText(tr("QFontDialog"));
    _layoutMain->addWidget(_btpFontDialog);

    connect(_btpFontDialog, SIGNAL(pressed()),
            _dlgFont, SLOT(show()));
}

