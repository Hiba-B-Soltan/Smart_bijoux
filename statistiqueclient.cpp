#include "statistiqueclient.h"
#include "ui_statistiqueclient.h"

statistiqueclient::statistiqueclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiqueclient)
{
    ui->setupUi(this);
}
void statistiqueclient::paintEvent(QPaintEvent *)
{

     int A=cl.statistique1();
     int B=cl.statistique2();
     int C=cl.statistique3();

            float s1= A*100 ;
            float s2=B*100;
            float s3=C*100;
            float nb = A+B+C;
            float q1 ;
            q1 = s1/nb ;
            float q2;
            q2=s2/nb;
            float q3;
            q3=s3/nb;
            float y  ;
            y= (q1*360)/100;
            float m;
            m= (q2*360)/100;
            float x;
            x= (q3*360)/100;

            float res1 = 16*y;
            float res2 = 16*m;
            float res3 = 16*x;


                        QPieSeries *series = new QPieSeries();
                        series->append("Produit Electrique", res1);
                        series->append("Produit Mecanique", res2);
                        series->append("Produit Informatique", res3);

                        QChart *chart = new QChart();
                        chart->addSeries(series);
                        chart->setTitle("Statistique par rapport au type de produit du client");

                        chartView = new QChartView(chart,ui->label);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->setMinimumSize(850,600);
                        chartView->show();
   }
statistiqueclient::~statistiqueclient()
{
    delete ui;
}

void statistiqueclient::on_pushButton_11_clicked()
{
    close();
}
