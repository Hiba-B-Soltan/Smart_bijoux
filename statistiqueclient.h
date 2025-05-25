#ifndef STATISTIQUECLIENT_H
#define STATISTIQUECLIENT_H

#include <QDialog>
#include <QtCharts>
#include "crudclient.h"

namespace Ui {
class statistiqueclient;
}

class statistiqueclient : public QDialog
{
    Q_OBJECT
protected:
   void paintEvent(QPaintEvent *);
public:
    explicit statistiqueclient(QWidget *parent = nullptr);
    ~statistiqueclient();

private slots:
   void on_pushButton_11_clicked();



private:
    Ui::statistiqueclient*ui;
    QVector<QPointF> dataPoints;
    QtCharts::QChartView *chartView;
    QtCharts::QLineSeries *series;
    crudclient cl;
};

#endif // STATISTIQUECLIENT_H
