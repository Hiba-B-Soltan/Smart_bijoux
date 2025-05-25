#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Connexion {
public:
    Connexion();
    ~Connexion();

    bool isConnected();  // Méthode pour vérifier la connexion

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
