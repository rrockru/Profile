#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore>
#include <QtGui>

class Settings : public QSettings
{
    Q_OBJECT
public:
    explicit Settings(QString fileName, QObject *parent = 0);
    ~Settings();

    void SaveSettings();
    void LoadSettings();

    QString GetDBServer() { return _dbServer; }
    void SetDBServer(QString param) { _dbServer = param; }
    QString GetDBDriver() { return _dbDriver; }
    void SetDBDriver(QString param) { _dbDriver = param; }
    QString GetDBName() { return _dbName; }
    void SetDBName(QString param) { _dbName = param; }
    QString GetDBUser() { return _dbUser; }
    void SetDBUser(QString param) { _dbUser = param; }
    QString GetDBPassword() { return _dbPassword; }
    void SetDBPassword(QString param) { _dbPassword = param; }
    
private:
    QString _dbServer;
    QString _dbDriver;
    QString _dbName;
    QString _dbUser;
    QString _dbPassword;
    
};

#endif // SETTINGS_H
