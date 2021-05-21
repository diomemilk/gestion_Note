#include "dbaccess.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

// Here we define the static DBAccess pointer
DBAccess* DBAccess::instance = nullptr;

DBAccess* DBAccess::getInstance() {
   if (instance == nullptr) {
      instance = new DBAccess();
   }

   return instance;
}

void DBAccess::release() {
   if (instance != nullptr) {
      delete instance;
   }
}

DBAccess::DBAccess()
{
    /*
     * Créer une base de données SQLITE avec "DB browser for SQLite"
     */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/hp/Documents/Projet QT/gestion_Note/gestion_notes.db");


    /***
    db.open();
     qDebug() << db.lastError();
    qDebug() << "DBAccess Object created and 'gestion_notes.db' has been added as default database!";
    QSqlQuery query;

    query.exec("SELECT * FROM t_users ");
     while(query.next()){
            qDebug() << query.value(3).toString();
     }
     ***/

}

bool DBAccess::open()
{
    if (db.isOpen()) return true;

    if (db.open())
    {
       qDebug() << "Connection opened with QSQLITE Database [OK]";
       return true;
    }
    else
    {
       qDebug() << "Connection failure with QSQLITE Database [KO]";
       return false;
    }
}

void DBAccess::close()
{
    if (!db.isOpen()) return;

    db.close();
    qDebug() << "Connection closed with QSQLITE Database [OK]";
}

DBAccess::~DBAccess()
{
    qDebug() << "DBAccess Object has been deleted!";
}
