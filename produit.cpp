#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include "qrcode.h"
#include <QtSvg/QSvgRenderer>
#include <fstream>

QT_CHARTS_USE_NAMESPACE

Produit::Produit()
{
  id_prduit=0; quantite=0; prix=0; poids=0; fournisseur=0 ; materiaux="" ; couleur="" ;
}


Produit::Produit(int id_prduit,int quantite,float prix,float poids,int fournisseur,QString materiaux,QString couleur)
{
    this->id_prduit=id_prduit;
    this->quantite=quantite;
    this->prix=prix;
    this->poids=poids;
    this->fournisseur=fournisseur;
    this->materiaux=materiaux;
    this->couleur=couleur;
}
//getters
int Produit:: getid_produit(){return id_prduit;}
int Produit:: get_quantite(){return quantite; }
float Produit:: get_prix(){return prix; }
float Produit:: get_poids(){return poids; }
int Produit:: get_fournisseur(){return fournisseur; }
QString Produit:: get_materiaux(){return materiaux; }
QString Produit:: get_couleur(){return couleur; }

//setters
void Produit:: setid_produit(int id_produit){this->id_prduit=id_produit; }
void Produit:: set_quantite(int quantite){this->quantite=quantite; }
void Produit:: set_prix(float prix){this->prix=prix; }
void Produit:: set_poids(float poids){this->poids=poids; }
void Produit:: set_fournisseur(int fournisseur){this->fournisseur=fournisseur;}
void Produit:: set_materiaux(QString materiaux){this->materiaux=materiaux;}
void Produit:: set_couleur(QString couleur){this->couleur=couleur;}

//fonctionnalites
bool Produit:: ajouter_produit()
{
    QSqlQuery query;
    QString id= QString:: number(id_prduit);
    QString quant= QString:: number(quantite);
    QString fourn= QString:: number(fournisseur);
    QString pr= QString:: number(prix);
    QString po= QString:: number(poids);
          query.prepare("INSERT INTO produit (id_prduit, quantite, prix, poids, fournisseur, materiaux, couleur) "
                        "VALUES (:id_prduit, :quantite, :prix, :poids, :fournisseur, :materiaux, :couleur)");

          query.bindValue(":id_prduit",id);
          query.bindValue(":quantite", quant);
          query.bindValue(":prix", pr);
          query.bindValue(":poids",po);
          query.bindValue(":fournisseur", fourn);
          query.bindValue(":materiaux", materiaux);
          query.bindValue(":couleur", couleur);
return query.exec();}

bool Produit:: supprimer_produit(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    QSqlQuery checkQuery;

     checkQuery.prepare("SELECT id_prduit FROM produit WHERE id_prduit =:id");
     checkQuery.bindValue(":id",res);
     if(checkQuery.exec()){
       if (checkQuery.next()) {
       query.prepare("Delete from produit where id_prduit= :id");
       query.bindValue(":id",res);}}

          return query.exec();
}

QSqlQueryModel * Produit:: afficher_produit()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from produit");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_prduit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("materiaux"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));

    return model;
}
QSqlQueryModel * Produit:: trier_prix()
{
        QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery("SELECT * from produit ORDER BY prix");
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_prduit"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("materiaux"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));

            return model ;
}
QSqlQueryModel * Produit:: trier_quantite()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from produit ORDER BY quantite");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_prduit"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("materiaux"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));

        return model ;
}

QSqlQueryModel * Produit:: trier_identifiant()
{
    QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from produit ORDER BY id_prduit");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_prduit"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("materiaux"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));

        return model ;
}


QSqlQueryModel* Produit ::recherche( int id)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;


            query.prepare("SELECT * from produit where id_prduit = :id");
           // model->setQuery("SELECT * from produit where id_prduit LIKE id");
                    query.addBindValue(id);
            query.exec();
            model->setQuery(query);
            model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_prduit"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("quantite"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("poids"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("fournisseur"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("materiaux"));
            model->setHeaderData(6,Qt::Horizontal,QObject::tr("couleur"));
            return model;
}


QString Produit::fetchProductInfoFromDatabase(int produit_id) {
    QSqlQuery query;
    query.prepare("SELECT quantite, fournisseur, prix, poid, materiaux, couleur FROM produit WHERE id_prduit = :produit_id");
    query.bindValue(":produit_id", produit_id);

    if (!query.exec()) {
        qDebug() << "Query error:" << query.lastError().text();
        return QString(); // Return an empty string on error
    }

    if (query.next()) {
        // Assuming your product information has the following data types
        int quantite = query.value(0).toInt();
        int fournisseur = query.value(1).toInt();
        float prix = query.value(2).toFloat();
        float poids = query.value(3).toFloat();
        QString materiaux = query.value(4).toString();
        QString couleur = query.value(5).toString();

        // Construct the product information string
        QString productInfo = QString("Quantite: %1\nFournisseur: %2\nPrix: %3\nPoids: %4\nMateriaux: %5\nCouleur: %6")
            .arg(quantite).arg(fournisseur).arg(prix).arg(poids).arg(materiaux).arg(couleur);

        return productInfo;
    } else {
        qDebug() << "No data found for productId:" << produit_id;
        return QString(); // Return an empty string if no data is found
    }
}


