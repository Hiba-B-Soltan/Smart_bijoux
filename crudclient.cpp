#include "crudclient.h"
#include<QtDebug>
#include <QObject>
#include <QSqlQuery>

crudclient::crudclient()
{
    id= 0;
    nom="";
    prenom="";
    adresse="";
    date_naissance="";
    telephone=0;
    produit="";
}
crudclient::crudclient(int id,QString nom,QString prenom,QString adresse,QString date_naissance,int telephone,QString produit)
{
    this->id=id;
    this->nom= nom;
    this->prenom= prenom;
    this->adresse=adresse;
    this->date_naissance=date_naissance;
    this->telephone=telephone;
    this->produit=produit;
}

int crudclient::getid(){
    return id;
}
void crudclient::setid(int id){
    this->id=id;
}
QString crudclient::getnom(){
    return nom;
}
void crudclient::setnom(QString nom){
    this->nom=nom;
}
QString crudclient::getprenom(){
    return prenom;
}
void crudclient::setprenom(QString prenom){
    this->prenom=prenom;
}
QString crudclient::getadresse(){
    return adresse;
}
void crudclient::setadresse(QString adresse){
    this->adresse=adresse;
}
QString crudclient::getdate_naissance(){
    return date_naissance;
}
void crudclient::setdate_naissance(QString date_naissance){
    this->date_naissance=date_naissance;
}
int crudclient::gettelephone(){
    return telephone;
}
void crudclient::settelephone(int telephone){
    this->telephone=telephone;
}
QString crudclient::getproduit(){
    return produit;
}
void crudclient::setproduit(QString produit){
    this->produit=produit;
}

bool crudclient::Ajouter()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString tel_string=QString::number(telephone);

         query.prepare("INSERT INTO client (id,nom,prenom,adresse,date_naissance,telephone,produit) "
                       "VALUES (:id,:nom,:prenom,:adresse,:date_naissance,:telephone,:produit)");
         query.bindValue(":id",id_string);
         query.bindValue(":nom",nom);
         query.bindValue(":prenom",prenom);
         query.bindValue(":adresse",adresse);
         query.bindValue(":date_naissance",date_naissance);
         query.bindValue(":telephone",tel_string);
         query.bindValue(":produit",produit);

      return query.exec();

}
QSqlQueryModel *crudclient::afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
        model->setQuery("SELECT * FROM client");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Naissance"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Produit"));

        return model;
}
bool crudclient::Supprime(int id)
{
    QSqlQuery query;
        query.prepare("delete from client where id=:id");
        query.bindValue(0, id);
    return query.exec();
}
bool crudclient::modifier()
{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString tel_string=QString::number(telephone);

query.prepare("UPDATE client SET nom=:nom,prenom=:prenom,adresse=:adresse,date_naissance=:date_naissance,telephone=:telephone,produit=:produit WHERE id=:id;");

query.bindValue(":id",id_string);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":date_naissance",date_naissance);
query.bindValue(":telephone",tel_string);
query.bindValue(":produit",produit);

    return query.exec();
}
// ## Recherche ## //

QSqlQueryModel *crudclient::afficher_nom(QString ch)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    model->setQuery("SELECT * FROM client where nom= '"+ch+"' ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Naissance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Produit"));

    return model;
}
// ## Tri ## //

QSqlQueryModel *crudclient:: afficher_nom1()
{
    QSqlQueryModel * model =new QSqlQueryModel();

        model->setQuery("SELECT * FROM client  ORDER BY id ASC ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Naissance"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Produit"));

        return model ;
}


QSqlQueryModel *crudclient:: afficher_nom2()
{
     QSqlQueryModel * model =new QSqlQueryModel();

         model->setQuery("SELECT * FROM client  ORDER BY id DESC;");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Naissance"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Telephone"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Produit"));

        return model ;
}
// ## Statistique ## //

int crudclient::statistique1(){

            int count=0 ;
            QSqlQuery requete("select * from client where produit like 'Produit Electrique'") ;
            while(requete.next())
            {
                    count++ ;
            }

        return count ;
}

int crudclient::statistique2(){

            int count=0 ;
            QSqlQuery requete("select * from client where produit like 'Produit Mecanique'") ;
            while(requete.next())
            {
                    count++ ;
            }

        return count ;
}
int crudclient::statistique3(){

            int count=0 ;
            QSqlQuery requete("select * from client where produit like 'Produit Informatique'") ;
            while(requete.next())
            {
                    count++ ;
            }

        return count ;
}
// PDF
crudclient* crudclient::readclient(QString val)
{
 QSqlQuery query;
     query.prepare("Select * FROM client where id='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {
             setid(query.value(0).toInt());
             setnom(query.value(1).toString());
             setprenom(query.value(2).toString());
             setadresse(query.value(3).toString());
             setdate_naissance(query.value(4).toString());
             settelephone(query.value(5).toInt());
             setproduit(query.value(6).toString());
            }
        }
     return this;
}

