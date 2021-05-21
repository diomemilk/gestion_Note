#ifndef SERVICE_H
#define SERVICE_H
#include "user.h"
#include "usermodel.h"
#include <QDebug>
#include <QMessageBox>

class Service
{
private:
    static Service* instance; // The single instance
     QString connection;
    Service();
    ~Service();

public:
    // How to get the single instance of Service
    static Service* getInstance();

    // How the release the single instance of DBAccess
    static void release();

    // Method pour User
    bool authentifier(QString login, QString password, User* user);
    void createUser(User user);
    void updateUser(User user);
    void removeUser(uint identifiant);
     QSqlQueryModel* listerUser();


};

#endif // SERVICE_H
