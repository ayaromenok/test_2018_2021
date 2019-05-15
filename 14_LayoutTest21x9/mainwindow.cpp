#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(0,0,2560,1080);

    createMenus();
    createToolbars();
    statusBar()->showMessage(tr("StatusBar message"));
}

MainWindow::~MainWindow()
{

}

void
MainWindow::createMenus()
{
    auto fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("New"));
    fileMenu->addAction(tr("Exit"));
}

void
MainWindow::createToolbars()
{
    auto fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(tr("New"));
    fileToolBar->addAction(tr("Exit"));
}
