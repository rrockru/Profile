#ifndef CONTROLS_H
#define CONTROLS_H

class Controls
{
public:
    Controls(QSqlDatabase &db);

    void SetCurrentUserID(int id) { _currentUserID = id; }
    int GetCurrentUserID() { return _currentUserID; }

    void SetCurrentRights(QString name) { _currentRights = name; }
    QString GetCurrentRights() { return _currentRights; }

    QSqlDatabase GetDatabase() { return _db; }

    void CloseDatabase();

private:
    int _currentUserID;

    QString _currentRights;

    QSqlDatabase _db;
};

#endif // CONTROLS_H
