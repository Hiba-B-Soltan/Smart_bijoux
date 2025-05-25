// logindialog.cpp
#include "logindialog.h"
#include "ui_logindialog.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonLogin_clicked()
{
    // Ajoutez votre logique de vérification d'identifiant et de mot de passe ici
    // Si la connexion réussit, émettez le signal loginSuccessful
    // Si la connexion échoue, affichez un message d'erreur
}
