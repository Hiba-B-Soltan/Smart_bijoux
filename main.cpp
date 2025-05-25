#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QPainter>
#include <QDebug>





int main(int argc, char *argv[])
{
    // Configuration du modèle de messages de débogage
        qSetMessagePattern("%{file}:%{line} - %{function}() %{message}");
    QApplication a(argc, argv);

    Connection c;

    bool test = c.createconnect();
    qDebug() << "Avant la création de MainWindow";
    MainWindow w;
    qDebug() << "Après la création de MainWindow";


    if (test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
            QObject::tr("connection successful.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject::tr("connection failed.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
    }

    return a.exec();
}
