#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

class LoginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDlg(QWidget *parent = 0);
    
signals:

private slots:
    void OnOkButton();
    void OnCancelButton();
};

#endif // LOGINWINDOW_H
