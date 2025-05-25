#include "statistique.h"
#include "produit.h"
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtWidgets/QGridLayout>
#include <QSqlQuery>
#include <QtDebug>
#include <QtSql>
#include <QPainter>

QT_CHARTS_USE_NAMESPACE
statistique::statistique():chart(nullptr){}

statistique::~statistique(){
    delete chart;
}

float statistique:: totalincome()
{
    float totalincome=0.0;
    QSqlQuery query1("SELECT quantite, prix FROM produit");
    while(query1.next())
    {
        int quantite = query1.value(0).toInt();
        float prix = query1.value(1).toFloat();
        float income=quantite * prix;
        totalincome+=income;
    }
    return  totalincome;
}

QChart* statistique:: generatePieChart()
{

    float total=totalincome();
    // Create a pie series
    QPieSeries *series = new QPieSeries();

    // Retrieve product information from the database
    QSqlQuery query("SELECT id_prduit, quantite, prix FROM produit");

    while (query.next()) {
        int productId = query.value(0).toInt();
        int quantity = query.value(1).toInt();
        float price = query.value(2).toFloat();

        // Calculate product income and percentage
        float productIncome = quantity * price;

        float percentage = (productIncome / total) * 100.0;

        // Create a pie slice for each product
        QPieSlice *slice = new QPieSlice(QString("Product Id: %1").arg(productId), percentage);
        series->append(slice);
    }
    // Create a chart
      QChart *chart = new QChart();
      chart->addSeries(series);
      chart->setTitle("Percentage of Income by Product");
      chart->setAnimationOptions(QChart::AllAnimations);

      return chart;
}
