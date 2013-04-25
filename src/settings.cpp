#include "settings.h"

Settings::Settings(QString fileName, QObject *parent) :
    QSettings(fileName, QSettings::IniFormat, parent)
{
    LoadSettings();
    SaveSettings();
}

Settings::~Settings()
{
    SaveSettings();
}

void Settings::LoadSettings()
{
    _dbServer = this->value("Connection/DBServer", "1.1.1.1").toString();
    _dbDriver = this->value("Connection/DBDriver", "SQL Server Native Client 11.0").toString();
    _dbName = this->value("Connection/DBName", "profilesdb").toString();
    _dbUser = this->value("Connection/DBUser", "sa").toString();
    _dbPassword = this->value("Connection/DBPassword", "password").toString();
}

void Settings::SaveSettings()
{
    this->setValue("Connection/DBServer", _dbServer);
    this->setValue("Connection/DBDriver", _dbDriver);
    this->setValue("Connection/DBName", _dbName);
    this->setValue("Connection/DBUser", _dbUser);
    this->setValue("Connection/DBPassword", _dbPassword);
}
