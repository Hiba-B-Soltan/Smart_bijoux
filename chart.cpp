#include "chart.h"
#include "employee.h"
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <QPainter>
#include<QBarSet>
#include<QBarSeries>
#include<QValueAxis>




QT_CHARTS_USE_NAMESPACE
chart::chart():stat(nullptr){}

chart::~chart(){
    delete stat;
}

 QChart* chart::statsexe()
 {
     int maleCount = 0;
        int femaleCount = 0;

        QSqlQuery query("SELECT sexe FROM employee");
        while (query.next()) {
            QString gender = query.value(0).toString();
            if (gender.toLower() == "masculin") {
                maleCount++;
            } else if (gender.toLower() == "feminin") {
                femaleCount++;
            }
            // Ajoutez plus de conditions pour d'autres options de genre si nécessaire
        }

        QPieSeries* series = new QPieSeries();

        QPieSlice* sliceFemale = series->append("Female", femaleCount);
        sliceFemale->setBrush(QColor("#FFB6C1")); // Définir la couleur pour la tranche "Female"

        QPieSlice* sliceMale = series->append("Male", maleCount);
        sliceMale->setBrush(QColor("#ADD8E6"
                                   "")); // Définir la couleur pour la tranche "Male"

        // Vous pouvez ajouter plus de tranches pour d'autres options de genre si nécessaire
        // Assurez-vous de définir les couleurs pour chaque tranche

        QChart* chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Distribution des genres");
        chart->setAnimationOptions(QChart::AllAnimations);

        return chart;
 }
