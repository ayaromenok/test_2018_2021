#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setGeometry(0,0,2560,1080);

    createMenus();
    createToolbars();
    createDockWidgets();
    createCentralWidget();
    statusBar()->showMessage(tr("StatusBar message"));
    _settings = new QSettings(this);
    restoreGeometry(_settings->value("geometry").toByteArray());
    restoreState(_settings->value("windowState").toByteArray());
    //restoreState();
}

MainWindow::~MainWindow()
{
    //saveState();
    _settings->setValue("geometry", saveGeometry());
    _settings->setValue("windowState", saveState());
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

void
MainWindow::createDockWidgets()
{
    QDockWidget *dockWidget = new QDockWidget(tr("Dock Widget"), this);
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea);
    QGroupBox *gbLeft = new QGroupBox(tr("gbLeft"), this);
    dockWidget->setWidget(gbLeft);
    addDockWidget(Qt::LeftDockWidgetArea, dockWidget);

    QDockWidget *dockWidgetR = new QDockWidget(tr("Dock Widget"), this);
    dockWidgetR->setAllowedAreas(Qt::LeftDockWidgetArea |
                                Qt::RightDockWidgetArea);
    QGroupBox *gbRight = new QGroupBox(tr("gbRight"), this);
    dockWidgetR->setWidget(gbRight);
    addDockWidget(Qt::RightDockWidgetArea, dockWidgetR);
}

void
MainWindow::createCentralWidget()
{
    QWidget     *wdCentral = new QWidget(this);
    QGridLayout *loutCentral = new QGridLayout(this);
    loutCentral->addWidget(new QGroupBox(tr("Top"), this), 0, 0);
    loutCentral->addWidget(new QGroupBox(tr("Persp"), this), 1, 0);
    loutCentral->addWidget(new QGroupBox(tr("Front"), this), 0, 1);
    loutCentral->addWidget(new QGroupBox(tr("Side"), this), 1, 1);
    wdCentral->setLayout(loutCentral);

    setCentralWidget(wdCentral);
}
