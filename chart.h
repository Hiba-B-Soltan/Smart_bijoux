#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>

QT_CHARTS_USE_NAMESPACE

class chart
{
public:
    chart();
    ~chart();
    QChart* statsexe();

    // You can add more functions or members as needed

private:
    QChart *stat;
};
