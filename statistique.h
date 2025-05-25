#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

QT_CHARTS_USE_NAMESPACE

class statistique
{
public:
    statistique();
    ~statistique();
    float totalincome();
    QChart* generatePieChart();

    // You can add more functions or members as needed

private:
    QChart *chart;
};
#endif // STATISTIQUE_H
