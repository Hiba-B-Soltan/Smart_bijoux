#ifndef PROMO_H
#define PROMO_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class promo;
}

class promo : public QDialog
{
    Q_OBJECT

public:
    explicit promo(QWidget *parent = nullptr);
    ~promo();
     int afficher_idclient(QString ch);
     QString promocode();

private slots:
     void on_recherche_clicked();

     void on_close_clicked();

private:
    Ui::promo *ui;
};

#endif // PROMO_H
