#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controls *controls, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    _controls = controls;

    ui->setupUi(this);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT name,enterprise,vacancy FROM ""profiles""");
    model->setHeaderData(0, Qt::Horizontal, tr("ФИО"));
    model->setHeaderData(1, Qt::Horizontal, tr("Предприятие"));
    model->setHeaderData(2, Qt::Horizontal, tr("Вакансия"));

    ui->tableView->setModel(model);
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
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
