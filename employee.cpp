#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QObject>
#include <QSqlError>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QString>
#include <QDebug>
#include "employee.h"
#include <QSqlQueryModel>
#include <QtSql>
#include <QPrinter>






employee::employee()
{

    id_employee = 0;

}


employee:: employee (int id_employee,QString nom ,QString prenom ,QString adr_mail ,QDate date_embauche ,QString titre_poste ,QString departement,QString performance ,QString langue_parlee ,QString sexe,QString mot_de_passe,QString question,QString reponse,QString idrf)
{    this->id_employee=id_employee;
     this->nom=nom;
     this->prenom=prenom;
     this->adr_mail=adr_mail;
     this->date_embauche=date_embauche;
     this->titre_poste=titre_poste ;
     this->departement=departement;
     this->performance=performance;
     this->langue_parlee=langue_parlee;
     this->sexe=sexe;
     this->mot_de_passe=mot_de_passe;
     this->question=question;
     this->reponse=reponse;
    this->idrf=idrf;
 }
void employee::set_identifiant(int id)
{
    id_employee = id;
}
void employee::set_nom(QString nom) {
    this->nom = nom;
}

void employee::set_prenom(QString prenom) {
    this->prenom = prenom;
}
void employee::set_adresse(QString adresse) {
    this->adr_mail = adresse;
}

void employee::set_date_embauche(QDate date) {
    this->date_embauche = date;
}

void employee::set_titre(QString titre) {
    this->titre_poste = titre;
}

void employee::set_performance(QString performance) {
    this->performance = performance;
}
void employee::set_departement(QString departement) {
    this->departement = departement;

}void employee::set_langue(QString langue) {
    this->langue_parlee = langue;
}
void employee::set_sexe(QString sexe) {
    this->sexe = sexe;
}
void employee::set_mot_de_passe(QString mot_de_passe) {
    this->mot_de_passe = mot_de_passe;
}
void employee::set_question(QString question) {
    this->question = question;
}
void employee::set_reponse(QString reponse) {
    this->reponse = reponse;
}

 int employee:: get_id(){return id_employee;};
 QString employee:: get_nom(){return nom;};
 QString employee:: get_prenom(){return prenom;};
 QString employee:: get_adr_mail(){return adr_mail;};
 QDate employee:: get_date_embauche(){return date_embauche;};
 QString employee::get_titre_poste(){return titre_poste;};
 QString employee::get_departement(){return departement ;};
 QString employee:: get_performance(){return performance;};
 QString employee::get_langue_paarlee (){return langue_parlee;};
 QString employee::get_sexe (){return sexe;};
 QString employee::get_mot_de_passe() {return mot_de_passe;};
 QString employee::get_question(){return question;};
 QString employee::get_reponse(){return reponse;};



 bool employee::ajouter_produit()
 {
     QSqlQuery query;
     QString id_string = QString::number(id_employee);
     query.prepare("INSERT INTO EMPLOYEE(ID_EMP, NOM, PRENOM, ADR_MAIL, DATE_EMBAUCHE, TITRE_POSTE, DEPARTEMENT, PERFORMANCE, LANGUE_PARLEE ,SEXE,MOT_DE_PASSE,QUESTION,REPONSE,IDRF) "
                   "VALUES (:id_employee, :nom, :prenom, :adr_mail, :date_embauche, :titre_poste, :departement, :performance, :langue_parlee,:sexe,:mot_de_passe,:question,:reponse,:idrf)");
     query.bindValue(":id_employee", id_string);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":adr_mail", adr_mail);
     query.bindValue(":date_embauche", date_embauche);
     query.bindValue(":titre_poste", titre_poste);
     query.bindValue(":departement", departement);
     query.bindValue(":performance", performance);
     query.bindValue(":langue_parlee", langue_parlee);
     query.bindValue(":sexe", sexe);
     query.bindValue(":mot_de_passe", mot_de_passe);
     query.bindValue(":question", question);
     query.bindValue(":reponse", reponse);
     query.bindValue(":idrf", idrf);

     if (query.exec()) {
         return true; // La requête s'est exécutée avec succès
     } else {
         qDebug() << "Erreur SQL : " << query.lastError().text();
         return false; // La requête a échoué
     }
 }
 QSqlQueryModel* employee::afficher()
 {
     QSqlQueryModel* model = new QSqlQueryModel();
     QSqlDatabase db = QSqlDatabase::database();

     if (db.isValid() && db.isOpen())
     {
         QString query = "SELECT ID_EMP, NOM, PRENOM, ADR_MAIL, DATE_EMBAUCHE, TITRE_POSTE, DEPARTEMENT, PERFORMANCE, LANGUE_PARLEE, SEXE FROM employee";
         model->setQuery(query);

         if (model->lastError().isValid())
         {
             qDebug() << "Error in query: " << model->lastError().text();
         }
     }
     return model;
 }






 bool employee:: supprimer (int id_employee)
 {
     QSqlQuery query;
     query.prepare("Delete from employee where id_emp= :id_employee");
     query.bindValue(":id_employee",id_employee);
     return query.exec();
 }




 bool employee::modifierEmploye(int id_emp, const QString &nom, const QString &prenom, const QString &adresse, const QDate &date_embauche, const QString &titre_poste, const QString &departement, const QString &performance, const QString &langue_parlee, const QString &sexe)
 {
     employee e;

     QSqlQuery rechercheQuery;
     rechercheQuery.prepare("SELECT * FROM employee WHERE ID_EMP = :id_employee");
     rechercheQuery.bindValue(":id_employee", id_emp);

     if (!rechercheQuery.exec())
     {
         qDebug() << "Erreur lors de la recherche de l'employé : " << rechercheQuery.lastError().text();
         return false;
     }

     if (rechercheQuery.next())
     {
         QSqlQuery miseAJourQuery;
         miseAJourQuery.prepare("UPDATE employee SET NOM = :nom, PRENOM = :prenom, ADR_MAIL = :adresse, DATE_EMBAUCHE = :date_embauche, TITRE_POSTE = :titre_poste, DEPARTEMENT = :departement, PERFORMANCE = :performance, LANGUE_PARLEE = :langue_parlee, SEXE = :sexe WHERE ID_EMP = :id_employee");
         miseAJourQuery.bindValue(":id_employee", id_emp);
         miseAJourQuery.bindValue(":nom", nom);
         miseAJourQuery.bindValue(":prenom", prenom);
         miseAJourQuery.bindValue(":adresse", adresse);
         miseAJourQuery.bindValue(":date_embauche", date_embauche);
         miseAJourQuery.bindValue(":titre_poste", titre_poste);
         miseAJourQuery.bindValue(":departement", departement);
         miseAJourQuery.bindValue(":performance", performance);
         miseAJourQuery.bindValue(":langue_parlee", langue_parlee);
         miseAJourQuery.bindValue(":sexe", sexe);

         if (miseAJourQuery.exec())
         {
             return true;
         }
         else
         {
             qDebug() << "Erreur lors de la mise à jour de l'employé : " << miseAJourQuery.lastError().text();
             return false;
         }
     }
     else
     {
         qDebug() << "Employé non trouvé.";
         return false;
     }
 }


 employee employee::rechercherEmployeParIdentifiant(int id_employee)
 {
     // Créez un objet employee vide pour stocker les informations de l'employé trouvé
     employee emp;

     // Connexion à la base de données
     QSqlDatabase db = QSqlDatabase::database();  // Assurez-vous que vous avez une connexion valide à votre base de données

     if (db.isValid() && db.isOpen()) {
         QSqlQuery query;

         // Exécutez une requête SQL pour rechercher l'employé par identifiant
         query.prepare("SELECT * FROM EMPLOYEE WHERE ID_EMP = :id_employee");
         query.bindValue(":id_employee", id_employee);

         if (query.exec()) {
             if (query.next()) {
                 // L'employé a été trouvé, remplissez l'objet employee avec les données de la base de données
                 emp.set_identifiant(query.value("ID_EMP").toInt());
                 emp.set_nom(query.value("NOM").toString());
                 emp.set_prenom(query.value("PRENOM").toString());
                 emp.set_adresse(query.value("ADR_MAIL").toString());
                 emp.set_date_embauche(query.value("DATE_EMBAUCHE").toDate());
                 emp.set_titre(query.value("TITRE_POSTE").toString());
                 emp.set_departement(query.value("DEPARTEMENT").toString());
                 emp.set_performance(query.value("PERFORMANCE").toString());
                 emp.set_langue(query.value("LANGUE_PARLEE").toString());
                 emp.set_sexe(query.value("SEXE").toString());
                 // Récupérez également le mot de passe
                                 emp.set_mot_de_passe(query.value("MOT_DE_PASSE").toString());

                 qDebug() << "Employé existant.";
             } else {
                 qDebug() << "Employé introuvable.";
             }
         } else {
             qDebug() << "Erreur SQL : " << query.lastError().text();
         }
     } else {
         qDebug() << "Connexion à la base de données invalide ou fermée.";
     }

     return emp;
 }

 QSqlQueryModel* employee::trierParIdentifiant()
 {
     QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM employee ORDER BY ID_EMP");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr-mail"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_embauche"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("titre_poste"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("performance"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("langue_parlee"));
     model->setHeaderData(8, Qt::Horizontal, QObject::tr("sexe"));
     return model;
 }


QSqlQueryModel* employee::trierParNom()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY nom");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr-mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_embauche"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("titre_poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("performance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("langue_parlee"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("sexe"));
    return model;
}

QSqlQueryModel* employee::trierParDateEmbauche()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY date_embauche");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr-mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_embauche"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("titre_poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("performance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("langue_parlee"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("sexe"));
    return model;
}

QSqlQueryModel* employee::trierParDepartement()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employee ORDER BY DEPARTEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_emp"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr-mail"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_embauche"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("titre_poste"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("departement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("performance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("langue_parlee"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("sexe"));
    return model;
}


// employee.cpp

employee employee::rechercherEmployeParIdentifiantRFID(const QString &rfid)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM employee WHERE rfid_column = :rfid");
    query.bindValue(":rfid", rfid);
    query.exec();

    employee emp;

    if (query.next()) {
        // Remplissez les données de l'employé à partir du résultat de la requête
        emp.set_identifiant(query.value("id_column").toInt());
        // ... Autres attributs ...
    }

    return emp;
}


