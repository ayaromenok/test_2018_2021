#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QVBoxLayout;
class QPushButton;
class QFileDialog;
class QColorDialog;
class QErrorMessage;
class QFontDialog;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
   void                 _addCheckBoxNative();
   void                 _addFileDialog();
   void                 _addColorDialog();
   void                 _addErrorDialog();
   void                 _addFontDialog();
   QVBoxLayout          *_layoutMain;
   QPushButton          *_btpFileDialog;
   QFileDialog          *_dlgFile;
   QPushButton          *_btpColorDialog;
   QColorDialog         *_dlgColor;
   QPushButton          *_btpErrorDialog;
   QErrorMessage        *_dlgError;
   QPushButton          *_btpFontDialog;
   QFontDialog          *_dlgFont;

};

#endif // WIDGET_H
