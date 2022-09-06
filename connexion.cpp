#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
