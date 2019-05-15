#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QSettings;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void createMenus();
    void createToolbars();
    void createDockWidgets();
    void createCentralWidget();

    QSettings   *_settings;
};

#endif // MAINWINDOW_H
