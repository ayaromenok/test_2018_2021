//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>
#include <QtGui>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setGeometry(100,100,640,400);
    QVBoxLayout *lt = new QVBoxLayout(this);
    QTextDocument *td = new QTextDocument("text");
    QTextEdit *te = new QTextEdit();
    te->setDocument(td);
    lt->addWidget(te);
    setLayout(lt);

    td->setMarkdown("# MD/GitHub\n## Level 2\n - [MD link](http://www.example.com)\n"
                    " - [local link](#llink)\n\n### Level 3\n Table\n\n"
                    "| Title #1 | Title #2 |\n|---|---|\n|value #1| value #2|\n"
                    " - **check** `text`/*MD* output in `console`",
                    QTextDocument::MarkdownDialectGitHub);

      qInfo() << " Pain text:" << td->toPlainText() << "\n\n"
              << "GitHub MarkDown" << td->toMarkdown(QTextDocument::MarkdownDialectGitHub);
//    QTextCursor *tc = new QTextCursor(td);
//    tc->setPosition(4);
//    tc->insertText("\nadditional text");
//    tc->insertText("\n[MD link](http://www.example.com)");


}

Widget::~Widget()
{
}

