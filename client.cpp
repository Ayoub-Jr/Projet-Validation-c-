#include "client.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

client::client()
{
id_client=0;
cin=0;
nom="";
prenom="";
matricule="";
email="";
}

client::client(int id_client,int cin,QString nom,QString prenom,QString matricule,QString email)
{
  this->id_client=id_client;
  this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
  this->matricule=matricule;
  this->email=email;
}

int client::get_id_client(){return id_client;}
int client::get_cin(){return  cin;}
QString client::get_nom(){return nom;}
QString client::get_prenom(){return prenom ;}
QString client::get_matricule(){return matricule;}
QString client::get_email(){return email;}



bool client::ajouter()
{
QSqlQuery query;

QString res= QString::number(id_client);

query.prepare("INSERT INTO client (id_client,cin,nom,prenom,matricule,email) "
                    "VALUES (:id_client,:cin,:nom,:prenom,:matricule,:email)");

query.bindValue(":id_client",res);

query.bindValue(":cin",cin);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":matricule",matricule);
query.bindValue(":email",email);



return    query.exec();
}

QSqlQueryModel * client::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from client");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MATRICULE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));

return model;
}

bool client::supprimer(int id_client)
{
    QSqlQuery query;


    QString res= QString::number(id_client);

    query.prepare("Delete from client where id_client= :id_client");
    query.bindValue(":id_client", res);
    return    query.exec();
}




bool client::modifier(int id_client,int cin,QString nom,QString prenom,QString matricule,QString email)
{ QSqlQuery query;
    QString res1= QString::number(id_client);
    QString res2= QString::number(cin);

    query.prepare("update client set id_client=:id_client,cin=:cin,nom=:nom,prenom=:prenom,matricule=:matricule,email=:email where id_client=:id_client");
    query.bindValue(":id_client",res1);
    query.bindValue(":cin",res2);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":matricule", matricule);
    query.bindValue(":email",email);

    return    query.exec();

}


QSqlQueryModel * client::chercher_matricule(QString N )
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM client WHERE matricule ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model ;
}
QSqlQueryModel * client::chercher_email(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM client WHERE email ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model ;
}
QSqlQueryModel * client::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client ORDER BY id_client asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel * client::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client ORDER BY nom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}
QSqlQueryModel * client::trier_prenom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM client ORDER BY prenom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("matricule"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("email"));

    return model;
}
