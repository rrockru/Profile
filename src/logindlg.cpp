#include "stdafx.h"
#include "logindlg.h"

LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *vbox = new QVBoxLayout;

    QComboBox *login = new QComboBox(this);
    QLineEdit *password = new QLineEdit(this);
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
}

void LoginDlg::OnOkButton()
{
    done(true);
}

void LoginDlg::OnCancelButton()
{
    done(false);
}
