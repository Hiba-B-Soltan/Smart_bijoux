#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Produit
{
private:
  int id_prduit;
  int quantite;
  int fournisseur;
  float prix;
  float poids;
  QString materiaux,couleur;


public:
    //constructors
    Produit();
    Produit(int,int,float,float,int,QString,QString);

    //getters
    int getid_produit();
    int get_quantite();
    float get_prix();
    float get_poids();
    int get_fournisseur();
    QString get_materiaux();

    QString get_couleur();

    //setters
    void setid_produit(int);
    void set_quantite(int);
    void set_prix(float);
    void set_poids(float);
    void set_fournisseur(int);
    void set_materiaux(QString);
    void set_couleur(QString);

    //fonctionnalites
    bool ajouter_produit();
    QSqlQueryModel * afficher_produit();
    QSqlQueryModel * trier_identifiant();
    QSqlQueryModel * trier_prix();
    QSqlQueryModel * trier_quantite();
    QSqlQueryModel * recherche_id(int);
    QSqlQueryModel* recherche( const QString& searchText);
    bool supprimer_produit(int);
    QString fetchProductInfoFromDatabase(int produit_id);

};

#endif // PRODUIT_H
