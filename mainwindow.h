#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include "arduino.h"
#include <QMainWindow>
#include <QSqlTableModel>
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QMenu>
#include <QtQuick>

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
    void setQR();
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void onComboBoxActivated(int index);
    void on_pb_modifier_clicked();
    void updateTabViewMod();
    void onReturnPressed();
    void on_chart1_clicked();
    void on_pb_export_clicked();
    void on_pb_QR_clicked();
    void on_pb_on_clicked();
    void on_pb_off_clicked();
private:
    Ui::MainWindow *ui;
    Produit pmp;
    Produit p;
    QByteArray data;
    Arduino A;

signals:
     void setCenterPosition(QVariant,QVariant);
     void setLocationMarking(QVariant,QVariant);
};
#endif // MAINWINDOW_H
