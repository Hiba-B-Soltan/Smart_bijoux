#ifndef CRUDCLIENT_H
#define CRUDCLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class crudclient
{
private:

    int id, telephone;
    QString nom ,prenom ,adresse ,produit, date_naissance;

public:
    crudclient();
    crudclient(int,QString,QString,QString,QString,int,QString);

    bool Ajouter();
    QSqlQueryModel* afficher();
    bool Supprime(int);
    bool modifier();

    int getid();
    void setid(int);
    QString getnom();
    void setnom(QString);
    QString getprenom();
    void setprenom(QString);
    QString getadresse();
    void setadresse(QString);
    QString getdate_naissance();
    void setdate_naissance(QString);
    int gettelephone();
    void settelephone(int);
    QString getproduit();
    void setproduit(QString);

    /*Recherche*/
    QSqlQueryModel *afficher_id(QString ch);
    QSqlQueryModel *afficher_nom(QString ch);
    QSqlQueryModel *afficher_contact(QString ch);
    /*Statistique*/
    int statistique1();
    int statistique2();
    int statistique3();
    /*PDF*/
    crudclient* readclient(QString val);
    /*Tri*/
    QSqlQueryModel *afficher_nom1();
    QSqlQueryModel *afficher_nom2();
};

#endif // CRUDCLIENT_H
