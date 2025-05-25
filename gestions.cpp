#include "gestions.h"
#include "ui_gestions.h"
#include"dialog.h"

gestions::gestions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestions)
{
    ui->setupUi(this);
}

gestions::~gestions()
{
    delete ui;
}

void gestions::on_emp_clicked()
{
    this->hide();
    Dialog dia;
    dia.setModal(true);
    dia.exec();
}
