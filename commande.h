#ifndef COMMANDE_H
#define COMMANDE_H

#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDateEdit>
#include <QRadioButton>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextTableCell>
#include <QTextTableFormat>
#include <QFileDialog>

QT_CHARTS_USE_NAMESPACE

class Commande
{
public:
    Commande();
    Commande(int,int,int ,QDate,QString,QDate,QString,int);


    int getn_commande();
    int getid_produit();
    int getcin_client();
    QDate getdate_commande();
    QString getmethode_paiement();
    QDate getdate_paiement();
    QString gettype_promo();
    int getprix();

    void setn_commande(int);
    void setid_produit(int);
    void setcin_client(int);
    void setdate_commande(QDate);
    void setmethode_paiement(QString);
    void setdate_paiement(QDate);
    void settype_promo(QString);
    void setprix(int);


    bool ajouter();
    bool commandeExiste(int n_commande);
    bool supprimer(int n_commande);
    bool modifier(int,int,int ,QDate,QString,QDate,QString,int);
    QSqlQueryModel* afficher();
    QSqlQueryModel *trierParDateCommande();
    QSqlQueryModel *trierParIdProduit();
    QSqlQueryModel *trierParNCommande();
    QChartView* produitsLesPlusCommandesGraphique();



private:
    int n_commande;
    int id_produit;
    int cin_client;
    QDate date_commande;
    QDate date_paiement;
    QString methode_paiement;
    QString type_promo;
    int prix;

    QRadioButton *ouiRadioButton;
    QRadioButton *nonRadioButton;


};

#endif // COMMANDE_H
