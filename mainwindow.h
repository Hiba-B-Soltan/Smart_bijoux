#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include "commande.h"
#include "arduino.h"
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
   void  on_pb_modifier_clicked();

   void on_pb_trierdateC_clicked();
   void on_pb_trierNCommande_clicked();
   void on_pb_trierIdProduit_clicked();


   void on_pb_statistiques_clicked();

   void on_pb_exporter_pdf_clicked();

   void on_le_ncommande_recherche_textChanged(const QString &arg1);



   void on_buttonLock_clicked();

   void on_buttonUnlock_clicked();

private:
    Ui::MainWindow *ui;
    Commande C,CC;
    QSqlQueryModel *resultModel;
    QSerialPort serial;



};
#endif // MAINWINDOW_H
