#include "commande.h"
#include "mainwindow.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QDateEdit>
#include <QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSet>
#include <QtCharts/QCategoryAxis>
#include <QPdfWriter>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_CHARTS_USE_NAMESPACE

Commande::Commande()
{
    n_commande=0;
    id_produit=0;
    cin_client=0;
    date_commande = QDate(); // Initialisation de date_commande avec une QDate vide
    methode_paiement = "";
    date_paiement = QDate();
    type_promo = "";
    prix=0;
}

Commande:: Commande(int n_commande, int id_produit, int cin_client, QDate date_commande, QString methode_paiement, QDate date_paiement, QString type_promo,int prix)
{
    this->n_commande = n_commande;
    this->id_produit = id_produit;
    this->cin_client = cin_client;
    this->date_commande = date_commande;
    this->methode_paiement = methode_paiement;
    this->date_paiement = date_paiement;
    this->type_promo = type_promo;
    this->prix = prix;
}


int Commande::getn_commande() { return n_commande; }
int Commande::getid_produit() { return id_produit; }
int Commande::getcin_client() { return cin_client; }
QDate Commande::getdate_commande() { return date_commande; }
QString Commande::getmethode_paiement() { return methode_paiement; }
QDate Commande::getdate_paiement() { return date_paiement; }
QString Commande::gettype_promo() { return type_promo; }
int Commande::getprix() { return prix; }

void Commande::setn_commande(int n_commande) { this->n_commande = n_commande; }
void Commande::setid_produit(int id_produit) { this->id_produit = id_produit; }
void Commande::setcin_client(int cin_client) { this->cin_client = cin_client; }
void Commande::setdate_commande(QDate date_commande) { this->date_commande = date_commande; }
void Commande::setmethode_paiement(QString methode_paiement) { this->methode_paiement = methode_paiement; }
void Commande::setdate_paiement(QDate date_paiement) { this->date_paiement = date_paiement; }
void Commande::settype_promo(QString type_promo) { this->type_promo = type_promo; }
void Commande::setprix(int prix) { this->prix = prix; }


bool Commande::ajouter()
{
    QSqlQuery query;
    QString ncommande_string = QString::number(n_commande);
    QString idproduit_string = QString::number(id_produit);
    QString cin_string = QString::number(cin_client);
    QString prix_string = QString::number(prix);

    query.prepare("INSERT INTO commande (n_commande, id_produit, cin_client, date_commande, methode_paiement, date_paiement, type_promo, prix) "
                  "VALUES (:n_commande, :id_produit, :cin_client, :date_commande, :methode_paiement, :date_paiement, :type_promo, :prix)");

    query.bindValue(":n_commande", n_commande);
    query.bindValue(":id_produit", id_produit);
    query.bindValue(":cin_client", cin_client);
    query.bindValue(":date_commande", date_commande);
    query.bindValue(":methode_paiement", methode_paiement);
    query.bindValue(":date_paiement", date_paiement);
    query.bindValue(":type_promo", type_promo);
    query.bindValue(":prix", prix);

    qDebug() << "Valeurs ajoutées : " << n_commande << id_produit << cin_client << date_commande << methode_paiement << date_paiement << type_promo << prix;

    return query.exec();
}

    bool Commande::commandeExiste(int n_commande)
    {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM commande WHERE n_commande = :n_commande");
        query.bindValue(":n_commande", n_commande);

        if (query.exec() && query.next()) {
            int rowCount = query.value(0).toInt();
            return rowCount > 0;
        }

        return false;
    }


    bool Commande::supprimer(int n_commande)
    {
        QSqlQuery query;
        QString ncommande_string= QString::number (n_commande);
        query.prepare("DELETE FROM commande WHERE n_commande = :n_commande");
        query.bindValue(":n_commande", n_commande);

        return query.exec();
    }



   bool Commande::modifier(int,int,int ,QDate,QString,QDate,QString,int)
    {
        QSqlQuery query;

        query.prepare("UPDATE COMMANDE SET N_COMMANDE=:N_COMMANDE,ID_PRODUIT=:ID_PRODUIT,DATE_COMMANDE=:DATE_COMMANDE,METHODE_PAIEMENT=:METHODE_PAIEMENT,DATE_PAIEMENT=:DATE_PAIEMENT,TYPE_PROMO =:TYPE_PROMO,PRIX=:PRIX where CIN_CLIENT=:CIN_CLIENT");

        query.bindValue(":N_COMMANDE", n_commande);
        query.bindValue(":ID_PRODUIT", id_produit);
        query.bindValue(":CIN_CLIENT", cin_client);
        query.bindValue(":DATE_COMMANDE", date_commande);
        query.bindValue(":METHODE_PAIEMENT", methode_paiement);
        query.bindValue(":DATE_PAIEMENT", date_paiement);
        query.bindValue(":TYPE_PROMO", type_promo);
        query.bindValue(":PRIX", prix);

        return query.exec();
    }

   QSqlQueryModel *Commande::afficher()
   {
       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT n_commande, id_produit, cin_client, date_commande, methode_paiement, date_paiement, type_promo, prix FROM commande");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("N° Commande"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID du Produit"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN Client"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Commande"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Méthode de Paiement"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Paiement"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de Promo"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Prix du produit"));

       return model;
   }


   QSqlQueryModel *Commande::trierParDateCommande()
   {
       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT n_commande, id_produit, cin_client, date_commande, methode_paiement, date_paiement, type_promo FROM commande ORDER BY date_commande");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("N° Commande"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID du Produit"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN Client"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Commande"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Méthode de Paiement"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Paiement"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de Promo"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Prix du produit"));
       return model;
   }


   QSqlQueryModel *Commande::trierParIdProduit()
   {
       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT n_commande, id_produit, cin_client, date_commande, methode_paiement, date_paiement, type_promo, prix FROM commande ORDER BY id_produit");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("N° Commande"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID du Produit"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN Client"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Commande"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Méthode de Paiement"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Paiement"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de Promo"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Prix du produit"));

       return model;
   }

   QSqlQueryModel *Commande::trierParNCommande()
   {
       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT n_commande, id_produit, cin_client, date_commande, methode_paiement, date_paiement, type_promo, prix FROM commande ORDER BY n_commande");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("N° Commande"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID du Produit"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN Client"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Commande"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Méthode de Paiement"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de Paiement"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type de Promo"));
       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Prix du produit"));

       return model;
   }


   QChartView* Commande::produitsLesPlusCommandesGraphique()
   {
       QSqlQueryModel *model = new QSqlQueryModel();
       model->setQuery("SELECT id_produit, COUNT(id_produit) AS nombre_de_commandes FROM commande GROUP BY id_produit ORDER BY nombre_de_commandes DESC");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID du Produit"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre de Commandes"));

       QBarSet *set = new QBarSet("Nombre de Commandes");

       // Remplir le bar set avec les données
       int rowCount = model->rowCount();
       QStringList categories; // Liste des catégories (produits)

       for (int i = 0; i < rowCount; ++i) {
           int count = model->data(model->index(i, 1)).toInt();
           *set << count;

           QString produit = model->data(model->index(i, 0)).toString();
           categories << produit;
       }

       QBarSeries *series = new QBarSeries();
       series->append(set);

       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Produits les plus commandés");

       QBarCategoryAxis *axeX = new QBarCategoryAxis();
       axeX->append(categories);
       chart->addAxis(axeX, Qt::AlignBottom);
       series->attachAxis(axeX);

       QValueAxis *axeY = new QValueAxis();
       chart->addAxis(axeY, Qt::AlignLeft);
       series->attachAxis(axeY);

       QChartView *vueChart = new QChartView(chart);
       vueChart->setRenderHint(QPainter::Antialiasing);

       return vueChart;
   }

