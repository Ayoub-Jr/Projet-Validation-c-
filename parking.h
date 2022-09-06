#ifndef PARKING_H
#define PARKING_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class parking
{
public:
    parking();
    parking(int,QString,QString,QString,int);
    int get_id_parking();
    QString get_date_libre();
    QString get_matricule_p();
    QString get_type();
    int get_prix();

    bool ajouter_parking();
    QSqlQueryModel * afficher_parking();
    bool supprimer_parking(int);
    bool modifier_parking(int,QString,QString,QString,int);

    QSqlQueryModel * chercher_matricule_p(QString);
    QSqlQueryModel * chercher_type(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_type();
    QSqlQueryModel * trier_prix();


private:
    QString matricule_p,type,date_libre;
    int id_parking,prix;
};

#endif // PARKING_H
