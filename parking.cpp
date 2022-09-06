#include "parking.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

parking::parking()
{
id_parking=0;
date_libre="";
matricule_p="";
type="";
prix=0;
}

parking::parking(int id_parking,QString date_libre,QString matricule_p,QString type,int prix)
{
  this->id_parking=id_parking;
  this->date_libre=date_libre;
  this->matricule_p=matricule_p;
  this->type=type;
  this->prix=prix;
}

int parking::get_id_parking(){return id_parking;}
QString parking::get_date_libre(){return  date_libre;}
QString parking::get_matricule_p(){return matricule_p;}
QString parking::get_type(){return type ;}
int parking::get_prix(){return prix;}



bool parking::ajouter_parking()
{
QSqlQuery query;

QString res= QString::number(id_parking);

query.prepare("INSERT INTO parkings (id_parking,date_libre,matricule_p,type,prix) "
                    "VALUES (:id_parking,:date_libre,:matricule_p,:type,:prix)");

query.bindValue(":id_parking",res);

query.bindValue(":date_libre",date_libre);
query.bindValue(":matricule_p",matricule_p);
query.bindValue(":type",type);
query.bindValue(":prix",prix);



return    query.exec();
}

QSqlQueryModel * parking::afficher_parking()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from parkings");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_LIBRE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("TYPE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIX"));

return model;
}

bool parking::supprimer_parking(int id_parking)
{
    QSqlQuery query;


    QString res= QString::number(id_parking);

    query.prepare("Delete from parkings where id_parking= :id_parking");
    query.bindValue(":id_parking", res);
    return    query.exec();
}




bool parking::modifier_parking(int id_parking,QString date_libre,QString matricule_p,QString type,int prix)
{ QSqlQuery query;
    QString res1= QString::number(id_parking);
    QString res2= QString::number(prix);

    query.prepare("update parkings set id_parking=:id_parking,date_libre=:date_libre,matricule_p=:matricule_p,type=:type,prix=:prix where id_parking=:id_parking");
    query.bindValue(":id_parking",res1);
    query.bindValue(":date_libre",date_libre);
    query.bindValue(":matricule_p",matricule_p);
    query.bindValue(":type",type);
    query.bindValue(":prix", res2);

    return    query.exec();

}


QSqlQueryModel * parking::chercher_matricule_p(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM parkings WHERE matricule_p ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_parking"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_libre"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule_p"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model ;
}
QSqlQueryModel * parking::chercher_type(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM parkings WHERE type ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_parking"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_libre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule_p"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model ;
}
QSqlQueryModel * parking::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM parkings ORDER BY id_parking asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_parking"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_libre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule_p"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * parking::trier_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM parkings ORDER BY type asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_parking"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_libre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule_p"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
QSqlQueryModel * parking::trier_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM parkings ORDER BY prix asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_parking"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_libre"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("matricule_p"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
