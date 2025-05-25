// forgotpassworddialog.h

#ifndef FORGOTPASSWORDDIALOG_H
#define FORGOTPASSWORDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>  // Ajout pour les messages de débogage

class ForgotPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    ForgotPasswordDialog(QWidget *parent = nullptr);
    ~ForgotPasswordDialog(); // Ajout du destructeur

    QString getQuestionFromDatabase(const QString &id);
    QString getAnswerFromDatabase(const QString &id);

private slots:
    void checkAnswer();

private:
    QLineEdit *idLineEdit;
    QLabel *questionLabel;
    QLineEdit *answerLineEdit;
    QPushButton *checkButton;
    QVBoxLayout *layout;
};

#endif // FORGOTPASSWORDDIALOG_H
