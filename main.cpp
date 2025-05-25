#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "produit.h"
#include <QtDebug>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "qrcode.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnection();
    MainWindow w;
    Produit p;

    if(test)// connection etablir
    {
        w.show();

        QMessageBox::information(nullptr,QObject::tr("data base is open"),
                     QObject::tr("connection successful.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else // data base failed
        QMessageBox::critical(nullptr,QObject::tr("data base is not open"),
                     QObject::tr("connection failed.\n" "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
