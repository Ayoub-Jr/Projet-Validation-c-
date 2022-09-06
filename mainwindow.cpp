#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<smtp.h>

#include "qcustomplot.h"

#include <QPlainTextEdit>
#include <QPlainTextDocumentLayout>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmp.afficher());
    ui->tableView_2->setModel(tmp2.afficher_parking());
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::verifID_c()
{
    if (ui->lineEdit_id_c->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id_c->text().isEmpty())
        {
            ui->lineEdit_id_c->clear();

            ui->lineEdit_id_c->setPlaceholderText("contient que des chiffres") ;
            return false;
        }
        else
        {
            return true;
        }
}
bool MainWindow::verifCin()
{
    if (ui->lineEdit_cin_c->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_cin_c->text().isEmpty())
        {
            ui->lineEdit_cin_c->clear();

            ui->lineEdit_cin_c->setPlaceholderText("contient que des chiffres") ;
            return false;
        }
        else
        {
            return true;
        }
}
bool MainWindow::verifNom()
{
    if (ui->lineEdit_nom_c->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_nom_c->text().isEmpty())
    {
        ui->lineEdit_nom_c->clear();
        ui->lineEdit_nom_c->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifPrenom()
{
    if (ui->lineEdit_prenom_c->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_prenom_c->text().isEmpty())
    {
        ui->lineEdit_prenom_c->clear();
        ui->lineEdit_prenom_c->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifMatricule()
{
    if (ui->lineEdit_matricule_c->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_matricule_c->text().isEmpty())
    {
        ui->lineEdit_matricule_c->clear();
        ui->lineEdit_matricule_c->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}


bool MainWindow::verifID_p()
{
    if (ui->lineEdit_id_parking->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_id_parking->text().isEmpty())
        {
            ui->lineEdit_id_parking->clear();

            ui->lineEdit_id_parking->setPlaceholderText("contient que des chiffres") ;
            return false;
        }
        else
        {
            return true;
        }
}

bool MainWindow::verifType()
{
    if (ui->lineEdit_type->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_type->text().isEmpty())
    {
        ui->lineEdit_type->clear();
        ui->lineEdit_type->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}
bool MainWindow::verifMatriculeP()
{
    if (ui->lineEdit_matricule_p->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_matricule_p->text().isEmpty())
    {
        ui->lineEdit_matricule_p->clear();
        ui->lineEdit_matricule_p->setPlaceholderText("contient que des caracteres") ;
        return false;
    }
    else
    {
        return true;
    }

}

bool MainWindow::verifPrix()
{
    if (ui->lineEdit_prix->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_prix->text().isEmpty())
        {
            ui->lineEdit_prix->clear();

            ui->lineEdit_prix->setPlaceholderText("contient que des chiffres") ;
            return false;
        }
        else
        {
            return true;
        }
}


void MainWindow::on_pushButton_ajouter_c_clicked()
{
    client c;
        int id_client = ui->lineEdit_id_c->text().toInt();
        int cin= ui->lineEdit_cin_c->text().toInt();
        QString nom= ui->lineEdit_nom_c->text();
        QString prenom= ui->lineEdit_prenom_c->text();
        QString matricule= ui->lineEdit_matricule_c->text();
        QString email= ui->lineEdit_email_c->text();

      client C (id_client,cin,nom,prenom,matricule,email);
      bool test=C.ajouter();
      if(verifID_c()&&verifCin()&&verifNom()&&verifPrenom()&& verifMatricule())
        {
      if(test)
    {
          ui->tableView->setModel(tmp.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","client ajouté");
               ui->lineEdit_id_c->setText("");
               ui->lineEdit_cin_c->setText("");
               ui->lineEdit_nom_c->setText("");
               ui->lineEdit_prenom_c->setText("");
               ui->lineEdit_matricule_c->setText("");
               ui->lineEdit_email_c->setText("");
  }
}
  else

  {
  QMessageBox msgBox ;
    msgBox.setText("client non ajouté ");
    //msgBox.exec();
  }
}


void MainWindow::on_pushButton_supprimer_c_clicked()
{
    int id_client = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(id_client);
    if(test)
    {
        ui->tableView->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","client supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("client non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_rafraichir_clicked()
{
     ui->tableView->setModel(tmp.afficher());
}


void MainWindow::on_pushButton_rafraichir_c_clicked()
{
    ui->tableView->setModel(tmp.afficher());
}


void MainWindow::on_pushButton_modifier_c_clicked()
{
    int id_client = ui->lineEdit_id_c->text().toInt();
    int cin= ui->lineEdit_cin_c->text().toInt();
    QString nom= ui->lineEdit_nom_c->text();
    QString prenom= ui->lineEdit_prenom_c->text();
    QString matricule= ui->lineEdit_matricule_c->text();
    QString email= ui->lineEdit_email_c->text();




          bool test=tmp.modifier(id_client, cin, nom, prenom, matricule, email);
          if(verifID_c()&&verifCin()&&verifNom()&&verifPrenom()&& verifMatricule())
            {
             if (test)
             {
                  ui->tableView->setModel(tmp.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","client bien Modifié");
                       ui->lineEdit_id_c->setText("");
                       ui->lineEdit_cin_c->setText("");
                       ui->lineEdit_nom_c->setText("");
                       ui->lineEdit_prenom_c->setText("");
                       ui->lineEdit_matricule_c->setText("");
                       ui->lineEdit_email_c->setText("");

                }
          }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{

    ui->lineEdit_id_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_cin_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_nom_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_prenom_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_matricule_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->lineEdit_email_c->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());

}


void MainWindow::on_pushButton_2_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_tri_id_clicked()
{
    ui->tableView->setModel(tmp.trier_id());
}


void MainWindow::on_pushButton_tri_nom_clicked()
{
    ui->tableView->setModel(tmp.trier_nom());
}


void MainWindow::on_pushButton_tri_prenom_clicked()
{
    ui->tableView->setModel(tmp.trier_prenom());
}


void MainWindow::on_pushButton_clicked()
{
    QString valeur=ui->lineEdit_chercher_cin->text();
        client *c=new client();
        ui->tableView->setModel(c->chercher_matricule(valeur));
}



void MainWindow::on_pushButton_chercher_adresse_clicked()
{
    QString valeur=ui->lineEdit_chercher_email->text();
        client *c=new client();
        ui->tableView->setModel(c->chercher_email(valeur));
}


void MainWindow::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/jraidib/Desktop/projet_2A/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des Clients ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID CLIENT");
        painter.drawText(1700,3300,"CIN CLIENT");
        painter.drawText(3200,3300,"NOM CLIENT");
        painter.drawText(4700,3300,"PRENOM CLIENT");
        painter.drawText(6200,3300,"MATRICULE CLIENT");
        painter.drawText(7700,3300,"EMAIL CLIENT");



        QSqlQuery query;
        query.prepare("select * from client");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4700,i,query.value(3).toString());
            painter.drawText(6200,i,query.value(4).toString());
            painter.drawText(7700,i,query.value(5).toString());


           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/jraidib/Desktop/projet_2A/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}
bool envoie_Retour(bool msg)
{
    return msg;
}

void MainWindow::on_pushButton_envoyer_mail_clicked()
{
    Smtp* smtp = new Smtp("testutilisateurs1@gmail.com","Projets@Esprit2022","smtp.gmail.com",465);
    connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
    smtp->sendMail("testutilisateurs1@gmail.com", ui->lineEdit_mail->text(), ui->subject->text(), ui->msg->toPlainText());
    ui->lineEdit_mail->setText("");
    ui->subject->setText("");
    ui->msg->setText("");
}


void MainWindow::on_pushButton_ajouter_parking_clicked()
{
    parking p;
        int id_parking = ui->lineEdit_id_parking->text().toInt();
        QString date_libre= ui->lineEdit_date_libre->text();
        QString matricule_p= ui->lineEdit_matricule_p->text();
        QString type= ui->lineEdit_type->text();
        int prix= ui->lineEdit_prix->text().toInt();

      parking P(id_parking,date_libre,matricule_p,type,prix);
      bool test=P.ajouter_parking();

      if(verifID_p()&&verifType()&&verifMatriculeP()&&verifPrix())//controle de saisie
        {
      if(test)
    {
          ui->tableView_2->setModel(tmp2.afficher_parking());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","parking ajouté");
               ui->lineEdit_id_parking->setText("");
               ui->lineEdit_date_libre->setText("");
               ui->lineEdit_matricule_p->setText("");
               ui->lineEdit_type->setText("");
               ui->lineEdit_prix->setText("");
      }
}
  else

  {
  QMessageBox msgBox ;
    msgBox.setText("parking non ajouté ");
    //msgBox.exec();
  }
}


void MainWindow::on_pushButton_supprimer_parking_clicked()
{
    int id_parking = ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp2.supprimer_parking(id_parking);
    if(test)
    {
        ui->tableView_2->setModel(tmp2.afficher_parking());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","parking supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("parking non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_rafraichir_2_clicked()
{
    ui->tableView_2->setModel(tmp2.afficher_parking());
}


void MainWindow::on_pushButton_rafraichir_parking_clicked()
{
    ui->tableView_2->setModel(tmp2.afficher_parking());
}


void MainWindow::on_pushButton_modifier_parking_clicked()
{

        int id_parking = ui->lineEdit_id_parking->text().toInt();
        QString date_libre= ui->lineEdit_date_libre->text();
        QString matricule_p= ui->lineEdit_matricule_p->text();
        QString type= ui->lineEdit_type->text();
        int prix= ui->lineEdit_prix->text().toInt();



          bool test=tmp2.modifier_parking(id_parking,date_libre,matricule_p,type,prix);
          if(verifID_p()&&verifType()&&verifMatriculeP()&&verifPrix())//controle de saisie
            {
             if (test)
             {
                  ui->tableView_2->setModel(tmp2.afficher_parking());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","parking bien Modifié");
           ui->lineEdit_id_parking->setText("");
           ui->lineEdit_date_libre->setText("");
           ui->lineEdit_matricule_p->setText("");
           ui->lineEdit_type->setText("");
           ui->lineEdit_prix->setText("");
}
                }
}


void MainWindow::on_tableView_2_activated(const QModelIndex &index)
{

}


void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    ui->lineEdit_id_parking->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_date_libre->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_matricule_p->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_type->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_prix->setText(ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),4)).toString());

}


void MainWindow::on_pushButton_tri_id_2_clicked()
{
    ui->tableView_2->setModel(tmp2.trier_id());
}


void MainWindow::on_pushButton_tri_nom_2_clicked()
{
    ui->tableView_2->setModel(tmp2.trier_type());
}


void MainWindow::on_pushButton_tri_prenom_2_clicked()
{
    ui->tableView_2->setModel(tmp2.trier_prix());
}


void MainWindow::on_pushButton_2_quitter_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_quitter_2_clicked()
{
    close();
}


void MainWindow::on_pushButton_cherche_matricule_clicked()
{
    QString valeur=ui->lineEdit_chercher_matricule->text();
        parking *p=new parking();
        ui->tableView_2->setModel(p->chercher_matricule_p(valeur));
}


void MainWindow::on_pushButton_chercher_type_clicked()
{
    QString valeur=ui->lineEdit_chercher_type->text();
        parking *p=new parking();
        ui->tableView_2->setModel(p->chercher_type(valeur));
}


void MainWindow::on_pushButton_pdf_parking_clicked()
{
    QPdfWriter pdf("C:/Users/jraidib/Desktop/projet_2A/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des parkings ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID PARKING");
        painter.drawText(1700,3300,"DATE LIBRE");
        painter.drawText(3200,3300,"MATRICULE");
        painter.drawText(4700,3300,"TYPE");
        painter.drawText(6200,3300,"PRIX");



        QSqlQuery query;
        query.prepare("select * from parkings");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4700,i,query.value(3).toString());
            painter.drawText(6200,i,query.value(4).toString());
            //painter.drawText(7700,i,query.value(5).toString());


           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/jraidib/Desktop/projet_2A/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}

QVector<double> MainWindow::Statistique_vente()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT prix FROM parkings WHERE prix<=200");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT prix FROM parkings WHERE 200<prix and prix<=400");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT prix FROM parkings WHERE 400<prix and prix<=600");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT prix FROM parkings WHERE 600<prix and prix<=800");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT prix FROM parkings WHERE 800<prix ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot_vente()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique_vente());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6;
    QVector<QString> labels;
    labels<<"0-200"<<"200-400"<<"400-600"<<"600-800"<<"800-1000";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}


void MainWindow::on_pushButton_2_clicked()//stat
{
    MainWindow::makePlot_vente();
}

