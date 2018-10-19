#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QVBoxLayout;
class QPushButton;
class QFileDialog;
class QColorDialog;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
   void                 _addFileDialog();
   void                 _addColorDialog();
   QVBoxLayout*         _ltMain;
   QPushButton*         _bpDiagFile;
   QFileDialog*         _dlFile;
   QPushButton*         _bpDiagColor;
   QColorDialog*        _dlColor;

};

#endif // WIDGET_H
