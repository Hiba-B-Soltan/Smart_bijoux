// forgotpassworddialog.cpp

#include "forgotpassworddialog.h"
#include <QMessageBox>
#include<QSqlQuery>
ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent)
    : QDialog(parent)
{
    // Initialiser les widgets
    idLineEdit = new QLineEdit(this);
    questionLabel = new QLabel("", this); // Ajout du label pour la question
    answerLineEdit = new QLineEdit(this);
    checkButton = new QPushButton("Vérifier", this);

    // Connecter le bouton à la fonction de vérification
    connect(checkButton, SIGNAL(clicked()), this, SLOT(checkAnswer()));

    // Créer la mise en page
    layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Donnez votre identifiant:", this));
    layout->addWidget(idLineEdit);
    layout->addWidget(checkButton);

    // Ajout des nouveaux éléments pour la question et la réponse
    layout->addWidget(questionLabel);
    layout->addWidget(new QLabel("Entrer votre réponse:", this));
    layout->addWidget(answerLineEdit);
}


void ForgotPasswordDialog::checkAnswer()
{
    // Récupérer l'identifiant et la réponse
    QString id = idLineEdit->text();
    QString answer = answerLineEdit->text();

    // Ajoutez des messages de débogage
    qDebug() << "ID: " << id;
    qDebug() << "Entered answer: " << answer;

    // Récupérer la question associée à l'identifiant
    QString question = getQuestionFromDatabase(id);
    questionLabel->setText(question);  // Afficher le contenu de l'attribut "question"
    qDebug() << "Question from database: " << question;

    // Vérifier la réponse
    QString correctAnswer = getAnswerFromDatabase(id);
    qDebug() << "Correct answer from database: " << correctAnswer;

    if (answer == correctAnswer) {
        QMessageBox::information(this, "Connexion réussie", "Mot de passe récupéré avec succès!");
        accept();  // Fermer la boîte de dialogue avec un statut de réussite
    } else {
        QMessageBox::warning(this, "Connexion impossible", "La récupération du mot de passe a échoué.");
    }
}


QString ForgotPasswordDialog::getQuestionFromDatabase(const QString &id)
{
    // Ouvrir la connexion à la base de données
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chemin_vers_votre_base_de_donnees.db");

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données";
        return "";  // Retourner une chaîne vide en cas d'erreur
    }

    // Exécuter la requête pour récupérer la question
    QSqlQuery query;
    query.prepare("SELECT question FROM table_utilisateurs WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Récupérer la question depuis le résultat de la requête
        QString question = query.value(0).toString();
        return question;
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête";
        return "";  // Retourner une chaîne vide en cas d'erreur
    }


}

QString ForgotPasswordDialog::getAnswerFromDatabase(const QString &id)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("chemin_vers_votre_base_de_donnees.db");

    if (!db.open()) {
        qDebug() << "Erreur lors de l'ouverture de la base de données";
        return "";  // Retourner une chaîne vide en cas d'erreur
    }

    QSqlQuery query;
    query.prepare("SELECT reponse FROM utilisateurs WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        QString reponse = query.value(0).toString();
        return reponse;
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête";
        return "";  // Retourner une chaîne vide en cas d'erreur
    }
}


ForgotPasswordDialog::~ForgotPasswordDialog()
{
    // Nettoyer les ressources si nécessaire
}
