#include "stdafx.h"
#include "controls.h"
#include "logindlg.h"
#include "mainwindow.h"
#include "settings.h"

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    application.setApplicationName("Profile");
    application.setApplicationVersion("1.0.0");

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

    Controls *controls = new Controls(db);

    LoginDlg *loginDlg = new LoginDlg(controls);
    if(loginDlg->exec())
    {
        MainWindow *window = new MainWindow(controls);
        window->show();

        return application.exec();
    }
    else
        return 0;
}
