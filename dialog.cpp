#include "dialog.h"
#include "ui_dialog.h"
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

#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <connection.h>
#include "forgotpassworddialog.h"
#include <QSerialPort>
#include "dialog.h"
#include "chart.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

   /* connect(A.getserial(), &QSerialPort::readyRead, this, &Dialog::on_RFIDRead);

        int ret = A.connect_arduino();
        switch (ret) {
            case 0:
                qDebug() << "Arduino is available and connected to: " << A.getarduino_port_name();
                break;
            case 1:
                qDebug() << "Arduino is available but not connected to: " << A.getarduino_port_name();
                break;
            case -1:
                qDebug() << "Arduino is not available";
                break;
        }

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Erreur : Impossible d'ouvrir le port série.";
    }
*/
     ui->le_id->setValidator(new QIntValidator(0, 999999, this));
    ui->combo_sexe->addItem("masculin");
    ui->combo_sexe->addItem("feminin");



    employee e;
    ui->tab_affiche->setModel(e.afficher());
    ui->tab_affiche->setModel(e.trierParIdentifiant());
    ui->combo_tri->addItem("Identifiant");
    ui->combo_tri->addItem("Nom");
    ui->combo_tri->addItem("Date d'embauche");
    ui->combo_tri->addItem("departement");
    // ...

    qDebug() << "on_RFIDRead called";
}

void Dialog::on_combo_tri_currentIndexChanged(const QString &triType)
{
    employee e;
    if (triType == "Identifiant") {
        ui->tab_affiche->setModel(e.trierParIdentifiant());
    } else if (triType == "Nom") {
        ui->tab_affiche->setModel(e.trierParNom());
    } else if (triType == "Date d'embauche") {
        ui->tab_affiche->setModel(e.trierParDateEmbauche());
    } else if(triType== "Departement"){
        ui->tab_affiche->setModel(e.trierParDepartement());
    }
}
void Dialog::on_bt_ajouter_clicked()
{
   int id_emp = ui->le_id->text().toInt();
   QString nom = ui->le_nom->text();
   QString prenom = ui->le_prenom->text();
   QString adr_mail = ui->le_mail->text();
   QDate date_embauche = ui->le_date->date();
   QString titre_poste = ui->le_titre->text();
   QString departement = ui->le_departement->text();
   QString performance = ui->le_performance->text();
   QString langue_parlee = ui->le_langue->text();
   QString sexe = ui->combo_sexe->currentText(); // Obtenir la valeur du QComboBox
   QString mot_de_passe = ui->le_passe->text();
   QString question = ui->le_question->text();
   QString reponse = ui->le_rep->text();
   QString idrf = ui->le_rf->text();
   employee e(id_emp, nom, prenom, adr_mail, date_embauche, titre_poste, departement, performance, langue_parlee, sexe,mot_de_passe ,question,reponse,idrf);

   bool test = e.ajouter_produit();
   QMessageBox msgBox;
   if (test) {
       QMessageBox::information(nullptr, QObject::tr("TRES BIEN"),
           QObject::tr("Ajout effectué\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
       ui->tab_affiche->setModel(e.afficher());
       ui->tab_affiche->setModel(e.trierParIdentifiant());
   } else {
       QMessageBox::critical(nullptr, QObject::tr("Pas OK"),
           QObject::tr("Ajout non effectué.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
   }
}

void Dialog::on_bt_supperimer_clicked()
{
   employee e1;
   e1.set_identifiant(ui->le_id_supprimer->text().toInt());

   // Vérifier si l'employé avec l'identifiant donné existe
   if (e1.rechercherEmployeParIdentifiant(e1.get_id()).get_id() == e1.get_id()) {
       // L'employé existe, procéder à la suppression
       bool test = e1.supprimer(e1.get_id());
       QMessageBox msgBox;

       if (test) {
           QMessageBox::information(nullptr, QObject::tr("TRES BIEN"),
               QObject::tr("suppression avec succes\n"), QMessageBox::Cancel);
           ui->tab_affiche->setModel(e.afficher());
           ui->tab_affiche->show();
           ui->tab_affiche->setModel(e.trierParIdentifiant());
           ui->tab_affiche->show();
       } else {
           QMessageBox::critical(nullptr, QObject::tr("Pas OK"),
               QObject::tr("Echec du suppression\n"), QMessageBox::Cancel);
       }
   } else {
       // L'employé n'a pas été trouvé, afficher un message d'erreur
       QMessageBox::critical(nullptr, QObject::tr("Erreur"),
           QObject::tr("Identifiant non trouvé.\n"), QMessageBox::Cancel);
   }
}




void Dialog::on_bt_chercher_clicked()

{

   employee e;
   // Récupérer l'identifiant entré par l'utilisateur
   int id_employee = ui->saisir_id->text().toInt();

   // Utilisez la fonction rechercherEmployeParIdentifiant pour obtenir les informations de l'employé
   employee emp = e.rechercherEmployeParIdentifiant(id_employee);

   // Assurez-vous que l'employé a été trouvé
   if (emp.get_id() == id_employee) {
       // Remplissez les champs de l'interface utilisateur avec les informations de l'employé
       ui->li_id->setText(QString::number(emp.get_id()));  // Ajoutez cette ligne pour afficher l'identifiant
       ui->li_nom->setText(emp.get_nom());
       ui->li_prenom->setText(emp.get_prenom());
       ui->li_adresse->setText(emp.get_adr_mail());
       ui->li_date->setDate(emp.get_date_embauche());
       ui->li_titre->setText(emp.get_titre_poste());
       ui->li_departement->setText(emp.get_departement());
       ui->li_performance->setText(emp.get_performance());
       ui->li_langue->setText(emp.get_langue_paarlee());
       ui->li_sexe->setText(emp.get_sexe());
   } else {
       // L'employé n'a pas été trouvé, vous pouvez afficher un message d'erreur
       QMessageBox::critical(this, "Erreur", "Employé non trouvé.");
   }
}


void Dialog::on_bt_modifier_clicked()
{
   // Récupérer le nouvel identifiant saisi par l'utilisateur
   int nouvelId = ui->li_id->text().toInt();

   // Récupérer les autres informations de l'employé
   QString nom = ui->li_nom->text();
   QString prenom = ui->li_prenom->text();
   QString adr_mail = ui->li_adresse->text();
   QDate date_embauche = ui->li_date->date();
   QString titre_poste = ui->li_titre->text();
   QString departement = ui->li_departement->text();
   QString performance = ui->li_performance->text();
   QString langue_parlee = ui->li_langue->text();
   QString sexe = ui->li_sexe->text();

   // Appeler la fonction de mise à jour de l'employé en passant le nouvel identifiant
   bool modificationReussie = e.modifierEmploye(nouvelId, nom, prenom, adr_mail, date_embauche, titre_poste, departement, performance, langue_parlee,sexe);

   if (modificationReussie) {
       QMessageBox::information(this, "Modification réussie", "Les modifications ont été enregistrées.");
       ui->tab_affiche->setModel( e.afficher());
       ui->tab_affiche->show();
       ui->tab_affiche->setModel(e.trierParIdentifiant());
       ui->tab_affiche->show();
   } else {
       QMessageBox::critical(this, "Erreur de modification", "La modification a échoué.");
   }
}

void Dialog::on_bt_export_pdf_clicked()
{
   QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QString(), "Fichiers PDF (*.pdf)");

   if (fileName.isEmpty()) {
       return;  // L'utilisateur a annulé la sélection du fichier
   }

   // Créez le périphérique d'impression
   QPrinter printer(QPrinter::PrinterResolution);

   // Définissez le nom du fichier de sortie
   printer.setOutputFileName(fileName);
   printer.setOutputFormat(QPrinter::PdfFormat);

   // Créez un document QText pour contenir le contenu du PDF
   QTextDocument doc;

   // Créez un curseur pour ajouter du texte au document
   QTextCursor cursor(&doc);

   // Ajoutez un en-tête au document
   QTextCharFormat format;
   format.setFont(QFont("Arial", 16, QFont::Bold));
   cursor.insertText("Liste des Employés\n\n", format);

   // Obtenez le modèle de la table et parcourez les lignes pour ajouter les données au document
   QSqlQueryModel *model = new QSqlQueryModel();
   model = static_cast<QSqlQueryModel*>(ui->tab_affiche->model());
   int rowCount = model->rowCount();
   int colCount = model->columnCount();

   // Créez une table pour afficher les données
   QTextTable *table = cursor.insertTable(rowCount + 1, colCount);

   // Remplissez la première ligne avec les noms de colonnes
   for (int col = 0; col < colCount; ++col) {
       table->cellAt(0, col).firstCursorPosition().insertText(model->headerData(col, Qt::Horizontal).toString());
   }

   // Remplissez le reste de la table avec les données de la base de données
   for (int row = 0; row < rowCount; ++row) {
       for (int col = 0; col < colCount; ++col) {
           table->cellAt(row + 1, col).firstCursorPosition().insertText(model->data(model->index(row, col)).toString());
       }
   }

   // Imprimez le document sur le périphérique d'impression
   doc.print(&printer);

   QMessageBox::information(this, "Export PDF", "Exportation en PDF réussie !");
}

void Dialog::on_chart1_clicked()
{
   chart chartHandler;
       QChart* chart = chartHandler.statsexe();

       QChartView* chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);

       QMainWindow* chartWindow = new QMainWindow();
       chartWindow->setCentralWidget(chartView);
       chartWindow->resize(420, 300);
       chartWindow->show();

}

Dialog::~Dialog()
{
    A.close_arduino();

    delete ui;
}
void Dialog::on_RFIDRead()
{
   QString uid = A.read_RFID_card();

   QString idrfValue = "";

   // Execute SQL query to retrieve idrf value for the corresponding RFID card UID
   QSqlQuery query("SELECT idrf FROM employee WHERE uid = '" + uid + "'");

   if (query.exec()) {
       if (query.next()) {
           idrfValue = query.value(0).toString();
       }
   }


   if (uid == idrfValue) {
       qDebug() << "UIDs match";
       QMessageBox::information(this, "Connexion réussie", "employé trouvé !");
   }
   else
        QMessageBox::critical(this, "Connexion réussie", "employé n'est pas  trouvé !");
}

