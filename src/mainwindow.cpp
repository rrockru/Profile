#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow(Controls* controls) : QMainWindow()
{
    _controls = controls;

	setMinimumSize(QSize(300, 200));
	resize(850, 650);

    QMenu *file_menu = menuBar()->addMenu(tr("&File"));
    file_menu->addAction(tr("&Exit"), this, SLOT(close()));

    QMenu *tables_menu = menuBar()->addMenu(tr("&Tables"));
    tables_menu->addAction(tr("&Users"));

    QMenu *service_menu = menuBar()->addMenu(tr("&Service"));
    service_menu->addAction(tr("&Import"));

    QTextEdit *tmp = new QTextEdit(this);
    setCentralWidget(tmp);
}

MainWindow::~MainWindow()
{
}

void MainWindow::LoadSettings()
{

}

void MainWindow::SaveSettings()
{

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    _controls->CloseDatabase();
    SaveSettings();
    QMainWindow::closeEvent(event);
}
