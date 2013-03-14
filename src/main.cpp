#include "stdafx.h"
#include "mainwindow.h"
#include "logindlg.h"

#include <QtSql/QSqlDatabase>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    application.setApplicationName("Quest Soft Player");
    application.setApplicationVersion("5.0.0");

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
