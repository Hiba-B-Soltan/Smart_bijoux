#ifndef DIALOG_H
#define DIALOG_H
#include "employee.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QDate>
#include<QComboBox>
#include <QtCharts>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QDebug>
#include<QPrinter>

#include <QIntValidator>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <connection.h>
#include "forgotpassworddialog.h"
#include <QSerialPort>
#include "employee.h"
#include "arduino.h"  // Assurez-vous que le chemin est correct si le fichier est dans un dossier différent
#include <QMainWindow>
#include <QCloseEvent>
#include <QSerialPort>

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
   void on_bt_ajouter_clicked();
   void on_bt_supperimer_clicked();
   void on_bt_chercher_clicked();
   void on_bt_modifier_clicked();
   void on_combo_tri_currentIndexChanged(const QString &triType);
   void on_bt_export_pdf_clicked();
   void on_chart1_clicked();
   void on_RFIDRead();

private:
    Ui::Dialog *ui;

    QByteArray data;
     Arduino  A;
        employee e, e1, emp;
        int index_of_mot_de_passe;
        bool errorMessageShown;
        int nombreTentatives;
        int tentativesDeConnexion;
        QSerialPort *serial;
};

#endif // DIALOG_H
