#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "controls.h"

class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDlg(Controls *controls, QWidget *parent = 0);
    
signals:

private slots:
    void OnOkButton();
    void OnCancelButton();

private:
    Controls *_controls;

    QComboBox *login;
    QLineEdit *password;
};

#endif // LOGINWINDOW_H
