#include "connexion.h"

Connexion::Connexion() {
    // Configurez les paramètres de connexion ici
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("NOUR");
    db.setPassword("NOURISHA");
}

bool Connexion::isConnected() {
    if (db.open()) {
        qDebug() << "Connexion à la base de données réussie.";
        return true;
    } else {
        qDebug() << "Échec de la connexion à la base de données.";
        return false;
    }
}

Connexion::~Connexion() {
    // Code de destruction
}

