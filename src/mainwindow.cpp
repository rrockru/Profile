#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	setMinimumSize(QSize(300, 200));
	resize(850, 650);
	
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
    SaveSettings();
    QMainWindow::closeEvent(event);
}
