#include "client.h"
#include "ui_client.h"
#include "statistiqueclient.h"
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <promo.h>
#include "camera.h"

client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
/*
    QRegularExpression nom_prenom("[A-Za-z]*");
    QRegularExpression mail("[A-Za-z1-9@.]*");

    QValidator* validator_nom_prenom = new QRegularExpressionValidator(nom_prenom, this);
    QValidator* validator_mail = new QRegularExpressionValidator(mail, this);

    ui->nom->setValidator(validator_nom_prenom);
    ui->prenom->setValidator(validator_nom_prenom);
    ui->mail->setValidator(validator_mail);

    ui->identifiant->setValidator(new QIntValidator(9, 9999, this));
    ui->contact->setValidator(new QIntValidator(9, 99999999, this));
    ui->Supp->setValidator(new QIntValidator(9, 9999, this));


*/
    ui->label_20->setVisible(false);
    ui->label_22->setVisible(false);
}

client::~client()
{
    delete ui;
}


void client::on_pushButton_add_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString date_naissance=ui->lineEdit_date_naissance->text();
    int telephone=ui->lineEdit_telephone->text().toInt();
    QString produit=ui->label_20->text();

      ui->lineEdit_id->setText("");
      ui->lineEdit_nom->setText("");
      ui->lineEdit_prenom->setText("");
      ui->lineEdit_adresse->setText("");
      ui->lineEdit_date_naissance->setText("");
      ui->lineEdit_telephone->setText("");
      ui->comboBox->setCurrentIndex(0);

    crudclient ccl(id,nom,prenom,adresse,date_naissance,telephone,produit);
    ccl.Ajouter();
    ui->tableView->setModel(ccl.afficher());

}

void client::on_pushButton_edit_clicked()
{

    int id=ui->lineEdit_id_edit->text().toInt();
    QString nom=ui->lineEdit_nom_edit->text();
    QString prenom=ui->lineEdit_prenom_edit->text();
    QString adresse=ui->lineEdit_adresse_edit->text();
    QString date_naissance=ui->lineEdit_date_naissance_edit->text();
    int telephone=ui->lineEdit_telephone_edit->text().toInt();
    QString produit=ui->label_22->text();

      ui->lineEdit_id_edit->setText("");
      ui->lineEdit_nom_edit->setText("");
      ui->lineEdit_prenom_edit->setText("");
      ui->lineEdit_adresse_edit->setText("");
      ui->lineEdit_date_naissance_edit->setText("");
      ui->lineEdit_telephone_edit->setText("");
      ui->comboBox_1->setCurrentIndex(0);

    crudclient ccl(id,nom,prenom,adresse,date_naissance,telephone,produit);
    ccl.modifier();
    ui->tableView->setModel(ccl.afficher());
}

void client::on_pushButton_dell_clicked()
{
    crudclient cclS;
    cclS.setid(ui->lineEdit_sup->text().toInt());
    cclS.Supprime(cclS.getid());
    ui->tableView->setModel(cclS.afficher());
    ui->lineEdit_sup->setText("");
}

void client::on_pushButton_ref_clicked()
{
    ui->tableView->setModel(ccl.afficher());
}

void client::on_pushButton_3_clicked()
{
    QString val=ui->lineEditsearch->text();
    if(val!=""){
        ui->tableView->setModel(ccl.afficher_nom(val));
    }
}
void client::on_Trie_NOM_clicked()
{
    ui->tableView->setModel(ccl.afficher_nom1());
}

void client::on_Trie_NOM_2_clicked()
{
    ui->tableView->setModel(ccl.afficher_nom2());
}
/*
void client::on_pushButton_add_2_clicked()
{
    QString id = ui->identifiant->text();

       QSqlQuery query;
       query.prepare("SELECT * FROM client WHERE id = :id");
       query.bindValue(":id", id);

       if (query.exec() && query.next()) {
           QString nom = query.value(1).toString();
           QString prenom = query.value(2).toString();
           QString mail = query.value(3).toString();
           QString torg = query.value(4).toString();
           QString contact = query.value(5).toString();

           ui->nom->setText(nom);
           ui->prenom->setText(prenom);
           ui->mail->setText(mail);
           ui->comboBox_type->setCurrentText(torg);
           ui->contact->setText(contact);
       } else {
           QMessageBox::critical(nullptr, QObject::tr("Error !!"),
                                 QObject::tr(""
                                             "Cette identifiant n'existe pas!"), QMessageBox::Cancel);

       }
}
*/
void client::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString choix;
    if (arg1 == "produit electrique")
    {choix = "Produit Electrique";}
    else if (arg1 == "produit mecanique")
    {choix = "Produit Mecanique";}
    else if (arg1 == "produit informatique")
    {choix = "Produit Informatique";}
    ui->label_20->setText(choix);
}
void client::on_comboBox_1_currentTextChanged(const QString &arg1)
{
    QString choix;
    if (arg1 == "produit electrique")
    {choix = "Produit Electrique";}
    else if (arg1 == "produit mecanique")
    {choix = "Produit Mecanique";}
    else if (arg1 == "produit informatique")
    {choix = "Produit Informatique";}
    ui->label_22->setText(choix);
}

void client::on_pb_pdf_2_clicked()
{
    camera c;
    c.exec();
}

void client::on_pb_pdf_3_clicked()
{
    promo p;
    p.exec();
}

void client::on_pushButton_2_clicked()
{
    statistiqueclient sc;
    sc.exec();
}

void client::on_pb_pdf_clicked()
{
    QString idpdf=ui->PDF->text();
    crudclient * mnd ;
    mnd= ccl.readclient(idpdf);
    QString id= QString::number(mnd->getid());
    QString nom_string = mnd->getnom();
    QString prenom_string = mnd->getprenom();
    QString adresse_string= mnd->getadresse();
    QString date_naissance_string= mnd->getdate_naissance();
    QString telephone_string= QString::number(mnd->gettelephone());
    QString produit_string= mnd->getproduit();

QColor Color2(209, 148, 87);
QPrinter printer;
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setOutputFileName("C:/Users/mehdi/OneDrive/Desktop/last time/[new proj]/[done]/gestion client/pdf/"+nom_string+"_"+id+".pdf");
       QPainter painter;

       if(!painter.begin(&printer))
       {qWarning("failed to open file");}
        painter.setFont(QFont("Bahnschrift Light", 25));
        painter.setPen(Color2);
        painter.drawText(130,230,"Information relative au client");
        painter.setPen(Qt::black);
        QPen borderPen(Qt::black);
        borderPen.setWidth(1);
        painter.setPen(borderPen);
        painter.drawText(260,150,"Gestion Client");
        painter.setPen(Qt::black);
        painter.drawText(250,300,"ID : " + id);
        painter.drawText(250,400,"Nom : "+nom_string);
        painter.drawText(250,500,"Prenom : "+prenom_string);
        painter.drawText(250,600,"Adresse : " +adresse_string);
        painter.drawText(250,700,"Date Naissance : "+date_naissance_string);
        painter.drawText(250,800,"Telephone : "+telephone_string);
        painter.drawText(250,900,"Produit : "+produit_string);
        painter.end();
}



void client::on_pushButton_clicked()
{
    QString id = ui->lineEdit_id_edit->text();

       QSqlQuery query;
       query.prepare("SELECT * FROM client WHERE id = :id");
       query.bindValue(":id", id);

       if (query.exec() && query.next()) {
           QString nom = query.value(1).toString();
           QString prenom = query.value(2).toString();
           QString adresse = query.value(3).toString();
           QString date = query.value(4).toString();
           QString tel = query.value(5).toString();
           QString produit = query.value(6).toString();

           ui->lineEdit_nom_edit->setText(nom);
           ui->lineEdit_prenom_edit->setText(prenom);
           ui->lineEdit_adresse_edit->setText(adresse);
           ui->lineEdit_date_naissance_edit->setText(date);
           ui->lineEdit_telephone_edit->setText(tel);
           ui->comboBox_1->setCurrentText(produit);
       } else {
           QMessageBox::critical(nullptr, QObject::tr("Error !!"),
                                 QObject::tr(""
                                             "Cette identifiant n'existe pas!"), QMessageBox::Cancel);

       }
}
