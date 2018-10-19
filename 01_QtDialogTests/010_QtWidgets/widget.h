#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QVBoxLayout;
class QPushButton;
class QFileDialog;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
   void _addFileDialog();
   QVBoxLayout*         _ltMain;
   QPushButton*         _bpDiagFile;
   QFileDialog*         _dlFile;
};

#endif // WIDGET_H
