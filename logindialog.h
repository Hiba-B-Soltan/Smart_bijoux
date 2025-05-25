// logindialog.h
#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

signals:
    void loginSuccessful();

private slots:
    void on_pushButtonLogin_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
