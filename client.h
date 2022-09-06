#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class client
{
public:
    client();
    client(int,int,QString,QString,QString,QString);
    int get_id_client();
    int get_cin();
    QString get_nom();
    QString get_prenom();
    QString get_matricule();
    QString get_email();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString,QString,QString,QString);

    QSqlQueryModel * chercher_matricule(QString);
    QSqlQueryModel * chercher_email(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_prenom();


private:
    QString nom,prenom,matricule,email;
    int id_client,cin;
};

#endif // CLIENT_H
