#include "stdafx.h"
#include "mainwindow.h"
#include "logindlg.h"
#include "settings.h"

#include <QtSql>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    application.setApplicationName("Quest Soft Player");
    application.setApplicationVersion("5.0.0");

    QString configFile = QApplication::applicationDirPath() + QDir::separator() + "profile.ini";

    Settings* settings = new Settings(configFile);

    QSqlDatabase db = QSqlDatabase::addDatabase( "QODBC" );
    QString connString=QString("Driver={%1};Server=%2;Database=%3;").arg(settings->GetDBDriver(),
                                                 settings->GetDBServer(), settings->GetDBName());
    db.setDatabaseName(connString);
    db.setUserName(settings->GetDBUser());
    db.setPassword(settings->GetDBPassword());
    if (!db.open())
    {
        QMessageBox::critical(0, "Error!", db.lastError().text());
        return -1;
    }

    LoginDlg *loginDlg = new LoginDlg();
    if(loginDlg->exec())
    {
        MainWindow *window = new MainWindow();
        window->show();

        return application.exec();
    }
    else
        return 0;
}
