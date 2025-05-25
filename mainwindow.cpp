#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"

#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QObject>
#include <QDateEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableCell>
#include <QTextTableFormat>
#include <QFileDialog>
#include <QPrinter>
#include <QTableView>
#include <QSqlTableModel>
#include <QtSerialPort/QSerialPort>

#include "commande.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resultModel = new QSqlQueryModel(this);
    Commande commande; // Créez une instance de votre classe Commande

    ui->cin->setValidator(new QIntValidator(0, 99999999, this)); // Contrôle de saisie pour CIN
    ui->id_produit->setValidator(new QIntValidator(0, 99999999, this)); // Contrôle de saisie pour ID produit
    ui->le_ncommande->setValidator(new QIntValidator(0, 99999999, this)); // Contrôle de saisie pour le numéro de commande
    ui->le_ncommande_supp->setValidator(new QIntValidator(0, 99999999, this)); // Contrôle de saisie pour le numéro de commande a supprimer
    Commande C;
    ui->tab_commande->setModel(C.afficher());
    ui->prix_produit->setValidator(new QIntValidator(0, 999999999, this));

     connect(ui->pb_statistiques, SIGNAL(clicked()), this, SLOT(on_pb_statistiques_clicked()));
     // Configurer le port série
     serial.setPortName("COM7");
     serial.setBaudRate(QSerialPort::Baud9600);
     // Ouvrir le port série
     if (serial.open(QIODevice::ReadWrite)) {
         qDebug() << "Serial port opened successfully.";
     } else {
         qDebug() << "Error opening serial port:" << serial.errorString();
     }
}

MainWindow::~MainWindow()
{
    // Fermer le port série avant de détruire l'interface graphique
    if (serial.isOpen()) {
        serial.close();
    }
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int n_commande = ui->le_ncommande->text().toInt();
    int id_produit= ui->id_produit->text().toInt();
    int cin_client= ui->cin->text().toInt();
    QDate date_commande = QDate::fromString(ui->la_datecommande->text(), "dd/MM/yyyy");
    QDate date_paiement = QDate::fromString(ui->la_datepaiement->text(), "dd/MM/yyyy");
    QString type_promo = ui->le_typepromo->text();
    QString methode_paiement = ui->la_methpaiement->currentText();
    int prix = ui->prix_produit->text().toInt();


Commande C(n_commande,id_produit,cin_client, date_commande,methode_paiement,date_paiement,type_promo, prix);

bool test =C.ajouter();

if (test)
    {
        // Rafraîchit l'affichage des données dans le tableau
        ui->tab_commande->setModel(C.afficher());
        QMessageBox::information(this, "Succès", "Ajout effectué");

        ui->la_methpaiement->setEnabled(true);

    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Ajout non effectué");
    }
        ui->le_ncommande->clear();
        ui->id_produit->clear();
        ui->cin->clear();
        ui->la_datecommande->clear();
        ui->la_methpaiement->clear();
        ui->la_datepaiement->clear();
        ui->le_typepromo->clear();
        ui->prix_produit->clear();
}

void MainWindow::on_pb_supprimer_clicked()
{
    // Récupère l'identifiant de la commande à supprimer depuis l'interface utilisateur
    int n_commande = ui->le_ncommande_supp->text().toInt();

    Commande C1;
    C1.setn_commande(n_commande);

    // Vérifie si la commande existe avant de la supprimer
    if (C1.commandeExiste(n_commande)) {
        bool test = C1.supprimer(n_commande);

        if (test) {
            // Rafraîchit l'affichage des données dans le tableau
            ui->tab_commande->setModel(C1.afficher());

            QMessageBox::information(this, "Succès", "Suppression effectuée");
        } else {
            QMessageBox::critical(this, "Erreur", "Suppression non effectuée");
        }
    } else {
        QMessageBox::warning(this, "Erreur", "La commande n'existe pas.");
    }
}

void MainWindow::on_pb_modifier_clicked()
{    int n_commande = ui->le_ncommande->text().toInt();
     int id_produit= ui->id_produit->text().toInt();
     int cin_client= ui->cin->text().toInt();
     QDate date_commande = QDate::fromString(ui->la_datecommande->text(), "dd/MM/yyyy");
     QDate date_paiement = QDate::fromString(ui->la_datepaiement->text(), "dd/MM/yyyy");
     QString type_promo = ui->le_typepromo->text();
     QString methode_paiement = ui->la_methpaiement->currentText();
     int prix = ui->prix_produit->text().toInt();

    Commande CC(n_commande,id_produit,cin_client, date_commande,methode_paiement,date_paiement,type_promo,prix);
    bool test= CC.modifier(id_produit,n_commande,cin_client, date_commande,methode_paiement,date_paiement,type_promo,prix);
    if (test)


    {

            QMessageBox::information(nullptr, QObject::tr("modification avec succes"),
                                      QObject::tr("update successful.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tab_commande->setModel(CC.afficher());
        }
                      else

            QMessageBox::critical(nullptr, QObject::tr("update errer"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_trierdateC_clicked()
{
    Commande C;
    QSqlQueryModel *modeleTriParDate = C.trierParDateCommande();
    ui->tab_commande->setModel(modeleTriParDate);
}

void MainWindow::on_pb_trierNCommande_clicked()
{
    Commande C;
    QSqlQueryModel *modeleTriParNCommande = C.trierParNCommande();
    ui->tab_commande->setModel(modeleTriParNCommande);
}

void MainWindow::on_pb_trierIdProduit_clicked()
{
    Commande C;
    QSqlQueryModel *modeleTriParIdProduit = C.trierParIdProduit();
    ui->tab_commande->setModel(modeleTriParIdProduit);
}




void MainWindow::on_pb_statistiques_clicked()
{
    // Vérifiez si un graphique est déjà présent dans le verticalLayout
    if (ui->verticalLayout->count() > 0) {
        // Effacez tous les widgets actuels du verticalLayout
        QLayoutItem *child;
        while ((child = ui->verticalLayout->takeAt(0)) != 0) {
            delete child->widget();
            delete child;
        }
    }

    // Ajoutez le nouveau graphique au verticalLayout
    Commande C;
    QChartView* chartView = C.produitsLesPlusCommandesGraphique();
    ui->verticalLayout->addWidget(chartView);
}



void MainWindow::on_pb_exporter_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_commande->model()->rowCount();
    const int columnCount = ui->tab_commande->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
         <<  QString("<title>%1</title>\n").arg("Gestion Commandes")
         <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

            "<center> <H1>GESTION COMMANDES </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>N° Commande</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_commande->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_commande->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_commande->isColumnHidden(column)) {
                QString data = ui->tab_commande->model()->data(ui->tab_commande->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out <<  "</table> </center>\n"
            "</body>\n"
            "</html>\n";

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A3);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    doc.setHtml(strStream);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}


void MainWindow::on_le_ncommande_recherche_textChanged(const QString &arg1)
{
    Commande C;
    QSqlQueryModel *model=new QSqlQueryModel();
    QString query ="SELECT * FROM COMMANDE WHERE N_COMMANDE LIKE '%" + arg1 +"%'";
    model->setQuery(query);
    ui->tab_commande->setModel(model);

}




void MainWindow::on_buttonLock_clicked()
{
    // Envoyer la commande 'O' à l'Arduino lorsque le bouton de verrouillage est cliqué
    if (serial.isOpen()) {
        serial.write("O");
    }
}

void MainWindow::on_buttonUnlock_clicked()
{

    QString uid = ui->le_uid->text();
    QSqlQuery query;
    qDebug()<<"uid:"<<uid;
    query.prepare("SELECT COUNT(*) FROM employee WHERE idrf = :uid");
       query.bindValue(":uid", uid);

       if (!query.exec()) {
           qDebug() << "Error executing query";
           return;
       }

       // Check if the query returned any results
       if (query.first()) {
           int count = query.value(0).toInt();

           if (count > 0) {
               QMessageBox::information(this, " réussie", "employer exist");
               if (serial.isOpen()) {
                   serial.write("O");
               }
           } else {
               QMessageBox::warning(this, " failed", "employer doesn't exist");
               if (serial.isOpen()) {
                   serial.write("C");
               }
           }
       } else {
           qDebug() << "Error checking for UID existence";
       }
}
/*void MainWindow::on_buttonUnlock_clicked()
{
    // Envoyer la commande 'C' à l'Arduino lorsque le bouton de déverrouillage est cliqué
    if (serial.isOpen()) {
        serial.write("C");
    }
}*/
