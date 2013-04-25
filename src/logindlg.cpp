#include "stdafx.h"
#include "logindlg.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;

    QStringList logins;

    QSqlQuery query("SELECT login FROM users");
    while (query.next()) {
        logins << query.value(0).toString();
    }

    login = new QComboBox(this);
    login->addItems(logins);

    password = new QLineEdit(this);
    QLabel *loginLabel = new QLabel(tr("Login:"), this);
    QLabel *passwordLabel = new QLabel(tr("Password:"), this);

    QHBoxLayout *buttons = new QHBoxLayout;
    QPushButton *okButton = new QPushButton(tr("OK"), this);
    connect(okButton, SIGNAL(clicked()), this, SLOT(OnOkButton()));
    QPushButton *cancelButton = new QPushButton(tr("Cancel"), this);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnCancelButton()));
    buttons->addWidget(okButton);
    buttons->addWidget(cancelButton);

    vbox->addWidget(loginLabel);
    vbox->addWidget(login);
    vbox->addWidget(passwordLabel);
    vbox->addWidget(password);
    vbox->addLayout(buttons);

    setLayout(vbox);

    password->setFocus();
}

void LoginDlg::OnOkButton()
{
    QString q = QString("SELECT * FROM users WHERE login='%1' AND password='%2';").arg(login->currentText(), password->text());
    QSqlQuery query(q);
    if(query.numRowsAffected())
        done(true);
    else
    {
        QMessageBox::critical(this, tr("Error!"), tr("Invalid password!"));
    }
}

void LoginDlg::OnCancelButton()
{
    done(false);
}
