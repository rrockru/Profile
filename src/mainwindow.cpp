#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
	setMinimumSize(QSize(300, 200));
	resize(850, 650);
	
	_configFile = QApplication::applicationDirPath() + QDir::separator() + "profile.ini";

    QTextEdit *tmp = new QTextEdit(this);
    setCentralWidget(tmp);
	
	LoadSettings();
}

MainWindow::~MainWindow()
{
}

void MainWindow::LoadSettings()
{
	QSettings settings(_configFile, QSettings::IniFormat);
	_sqlServer = settings.value("Connection/SqlServer", "195.54.40.172").toString();
}

void MainWindow::SaveSettings()
{
	QSettings settings(_configFile, QSettings::IniFormat);
	settings.setValue("Connection/SqlServer", _sqlServer);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    SaveSettings();
    QMainWindow::closeEvent(event);
}
