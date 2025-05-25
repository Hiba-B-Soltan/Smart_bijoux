#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include "connexion.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion connexion;  // La connexion est établie dans le constructeur
    bool test =connexion.isConnected();
    MainWindow w;
    // Créez une instance de la classe Commande pour gérer l'exportation en PDF
       Commande commande;

    if (test) { // Vérifiez si la connexion est ouverte
        // Vous pouvez effectuer des opérations sur la base de données ici.
        w.show();
    } else {
        qDebug() << "Échec de la connexion à la base de données.";
    }

    return a.exec();
}
