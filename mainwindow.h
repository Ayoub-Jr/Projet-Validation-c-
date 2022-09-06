#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "parking.h"

#include <QMainWindow>
#include <QDialog>
#include <QObject>
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    bool verifID_c();
    bool verifCin();
    bool verifNom();
    bool verifPrenom();
    bool verifMatricule();



    bool verifID_p();
    bool verifType();
    bool verifMatriculeP();
    bool verifPrix();


    void on_pushButton_ajouter_c_clicked();

    void on_pushButton_supprimer_c_clicked();

    void on_pushButton_rafraichir_clicked();

    void on_pushButton_rafraichir_c_clicked();

    void on_pushButton_modifier_c_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_quitter_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_tri_id_clicked();

    void on_pushButton_tri_nom_clicked();

    void on_pushButton_tri_prenom_clicked();

    void on_pushButton_clicked();

    void on_pushButton_chercher_adresse_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_envoyer_mail_clicked();

    void on_pushButton_ajouter_parking_clicked();

    void on_pushButton_supprimer_parking_clicked();

    void on_pushButton_rafraichir_2_clicked();

    void on_pushButton_rafraichir_parking_clicked();

    void on_pushButton_modifier_parking_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_pushButton_tri_id_2_clicked();

    void on_pushButton_tri_nom_2_clicked();

    void on_pushButton_tri_prenom_2_clicked();

    void on_pushButton_2_quitter_2_clicked();

    void on_pushButton_quitter_2_clicked();

    void on_pushButton_cherche_matricule_clicked();

    void on_pushButton_chercher_type_clicked();

    void on_pushButton_pdf_parking_clicked();

    void makePlot_vente ();
    QVector<double> Statistique_vente();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    client tmp;
    parking tmp2;
};
bool envoie_Retour(bool msg);
#endif // MAINWINDOW_H
