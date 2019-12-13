//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>
#include <QtGui>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *lt = new QVBoxLayout(this);
    QTextDocument *td = new QTextDocument("text");
    QTextEdit *te = new QTextEdit();
    te->setDocument(td);
    lt->addWidget(te);
    setLayout(lt);


    QTextCursor *tc = new QTextCursor(td);
    tc->setPosition(4);
    tc->insertText("\nadditional text");
    tc->insertText("\n[MD link](http://www.example.com)");

}

Widget::~Widget()
{
}

