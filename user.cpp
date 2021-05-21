#include "user.h"

User::User()
{}

User::User(uint _identifiant, QString _nom, QString _prenom, QString _login, QString _password):
    identifiant(_identifiant), nom(_nom), prenom(_prenom), login(_login), password(_password)
{}

User::User(QString _nom, QString _prenom, QString _login, QString _password):
    nom(_nom), prenom(_prenom), login(_login), password(_password)
{}
