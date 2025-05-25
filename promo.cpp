#include "promo.h"
#include "ui_promo.h"
#include "crudclient.h"
#include <QSqlQuery>
#include <QMessageBox>

promo::promo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::promo)
{
    ui->setupUi(this);
}

promo::~promo()
{
    delete ui;
}
int promo::afficher_idclient(QString ch)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM client where id= '"+ch+"' ");
    query.exec();
    int count=0;
    while (query.next())
    {
        count++;
    }
    return count;
}
std::string generate_promo_code() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,sizeof(alphanum)-2);

    std::string promo_code(8, '\0');
    for (int i = 0; i < 8; ++i) {
        promo_code[i] = alphanum[dist(rng)];
    }

    return promo_code;
}
void promo::on_recherche_clicked()
{
     QString val=ui->lineEdit_recherche->text();
     if(val!="")
         {afficher_idclient(val);}

     if (afficher_idclient(val)>= 3){
        std::string promo= generate_promo_code();

         QString message = "merci pour votre fidélité !! \n voici votre code promo: "+QString::fromStdString(promo);
         QMessageBox::information(this, "Promo activée", message);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("Pas de Promo"),
                               QObject::tr("Désolé \n"
                                           "vous n'êtes pas un client fidéle"), QMessageBox::Cancel);
     }
}
void promo::on_close_clicked()
{
    close();
}
