#include "employee.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QDate>
#include<QComboBox>
#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QDebug>
#include<QPrinter>
#include<chart.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <connection.h>
#include "forgotpassworddialog.h"
#include <QSerialPort>
#include "dialog.h"
#include"gestions.h"
using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow),
   nombreTentatives(4),
   tentativesDeConnexion(0),
   serial(new QSerialPort(this))
{
   ui->setupUi(this);

   // Autres initialisations

   setupUiDefaults();
   connect(ui->checkBoxAfficherMotDePasse, SIGNAL(stateChanged(int)), this, SLOT(on_afficherMotDePasseChanged(int)));

}







MainWindow::~MainWindow()
{


       delete ui;
   }




void MainWindow::on_connexion_clicked()
{
   QString identifiantStr = ui->la_identifiant->text().trimmed();
   QString mot_de_passe = ui->la_passe->text();

   // Vérifier si les champs d'identifiant et de mot de passe ne sont pas vides
   if (identifiantStr.isEmpty() || mot_de_passe.isEmpty()) {
       QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
       return;  // Arrêter la fonction si l'un des champs est vide
   }

   // Créer un validateur pour s'assurer que la saisie est un entier
   QIntValidator validator;
   int pos = 0;

   // Vérifier si la saisie est un entier
   if (validator.validate(identifiantStr, pos) != QValidator::Acceptable) {
       QMessageBox::warning(this, "Erreur de saisie", "Veuillez entrer un identifiant valide (entier) !");
       return;  // Arrêter la fonction si la saisie n'est pas un entier
   }

   int identifiant = identifiantStr.toInt();

   // Rechercher l'employé par identifiant
   employee emp = e.rechercherEmployeParIdentifiant(identifiant);

   // Incrémenter le compteur de tentatives même si l'identifiant n'est pas trouvé
   tentativesDeConnexion++;

   // Vérifier si l'identifiant existe
   if (emp.get_id() == identifiant) {
       // L'identifiant existe, vérifier si le mot de passe correspond
       QString motDePasseEntered = mot_de_passe.trimmed();

       if (emp.get_mot_de_passe().compare(motDePasseEntered, Qt::CaseSensitive) == 0) {
           { // Mot de passe correct
           //QMessageBox::information(this, "Connexion réussie", "Connexion réussie !");
           this->hide();
           gestions gest;
           gest.setModal(true);
           gest.exec();
           }

           // Ajoutez ici le code pour passer à la nouvelle fenêtre ou effectuer d'autres actions après la connexion réussie.
       } else {
           // Mot de passe incorrect
           QMessageBox::warning(this, "Erreur de connexion", QString("Mot de passe incorrect ! Il vous reste %1 tentatives.").arg(4 - tentativesDeConnexion));
       }
   } else {
       // L'identifiant n'existe pas
       QMessageBox::warning(this, "Erreur de connexion", QString("Identifiant non trouvé ! Il vous reste %1 tentatives.").arg(4 - tentativesDeConnexion));
   }

   // Vérifier le nombre de tentatives
   if (tentativesDeConnexion >= 4) {
       // Bloquer le bouton de connexion
       ui->connexion->setEnabled(false);
       QMessageBox::warning(this, "Trop de tentatives", "Vous avez dépassé le nombre maximum de tentatives. Veuillez réessayer plus tard.");
   }
}


void MainWindow::setupUiDefaults()
{
   ui->la_passe->setEchoMode(QLineEdit::Password); // Initialisez le mode écho du champ de mot de passe à Password
}

void MainWindow::on_afficherMotDePasseChanged(int state)
{
   if (state == Qt::Checked) {
       ui->la_passe->setEchoMode(QLineEdit::Normal);
   } else {
       ui->la_passe->setEchoMode(QLineEdit::Password);
       // Assurez-vous de mettre à jour le texte après avoir changé le mode écho
       ui->la_passe->setText(ui->la_passe->text());
   }
}


void MainWindow::on_oublier_clicked()
{
   // Afficher une nouvelle fenêtre ou un dialogue pour la récupération du mot de passe
       ForgotPasswordDialog dialog(this);
       if (dialog.exec() == QDialog::Accepted) {
           // La récupération du mot de passe a été réussie
           QMessageBox::information(this, "Connexion réussie", "Mot de passe récupéré avec succès!");
       } else {
           // La récupération du mot de passe a échoué ou a été annulée
           QMessageBox::warning(this, "Connexion impossible", "La récupération du mot de passe a échoué.");
       }
}

