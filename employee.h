#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDate>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QString>

class employee
{
public:
   employee();
   employee(int id_emp, QString nom, QString prenom, QString adr_mail, QDate date_embauche, QString titre_poste, QString departement, QString performance, QString langue_parlee,QString sexe,QString mot_de_passe,QString question,QString reponse,QString idrf);
   //getters
   int get_id();
   QString get_nom();
   QString get_prenom();
   QString get_adr_mail();
   QDate get_date_embauche();
   QString get_titre_poste();
   QString get_departement ();
   QString get_performance();
   QString get_langue_paarlee ();
   QString get_sexe ();
   QString get_mot_de_passe() ;
   QString get_question();
   QString get_reponse() ;

       //setters

     void set_identifiant(int);
     void set_nom(QString);
     void set_prenom(QString);
     void set_adresse (QString);
     void set_date_embauche(QDate);
     void set_titre (QString);
     void set_departement (QString);
     void set_performance (QString);
     void set_langue(QString );
     void set_sexe(QString );
     void set_mot_de_passe(QString );
     void set_question( QString );
     void set_reponse( QString );



       //crud
     bool ajouter_produit();
     QSqlQueryModel* afficher();
     bool supprimer (int);
     bool modifierEmploye(int id_emp, const QString &nom, const QString &prenom, const QString &adresse, const QDate &date_embauche, const QString &titre_poste, const QString &departement, const QString &performance, const QString &langue_parlee,const QString &sexe);
     employee rechercherEmployeParIdentifiant(int id_employee);
     QSqlQueryModel* trierParIdentifiant();
     QSqlQueryModel* trierParNom();
     QSqlQueryModel* trierParDateEmbauche();
     QSqlQueryModel* trierParDepartement();
     employee rechercherEmployeParIdentifiantRFID(const QString &rfid);

       private:
           int id_employee;
           QString nom;
           QString prenom;
           QString adr_mail;
           QDate date_embauche;
           QString titre_poste;
           QString departement;
           QString performance;
           QString langue_parlee;
           QString sexe;
           QString mot_de_passe;
           QString question;
           QString reponse;
           QString idrf;
};

#endif // EMPLOYEE_H
