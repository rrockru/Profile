#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QtSql>

class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDlg(QWidget *parent = 0);
    
signals:

private slots:
    void OnOkButton();
    void OnCancelButton();

private:
    QComboBox *login;
    QLineEdit *password;
};

#endif // LOGINWINDOW_H
