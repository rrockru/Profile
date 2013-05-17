#include "stdafx.h"
#include "controls.h"

Controls::Controls(QSqlDatabase &db)
{
    _db = db;
}

void Controls::CloseDatabase()
{
    _db.close();
}
