#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employee.h"
#include "arduino.h"  // Assurez-vous que le chemin est correct si le fichier est dans un dossier différent
#include <QMainWindow>
#include <QCloseEvent>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
   ~MainWindow();

private slots:

   void on_connexion_clicked();
   void on_afficherMotDePasseChanged(int state);
   void setupUiDefaults();
   void on_oublier_clicked();








private:
       Ui::MainWindow *ui;

       QByteArray data;
        Arduino  A;
           employee e, e1, emp;
           int index_of_mot_de_passe;
           bool errorMessageShown;
           int nombreTentatives;
           int tentativesDeConnexion;
           QSerialPort *serial;


};

#endif // MAINWINDOW_H
