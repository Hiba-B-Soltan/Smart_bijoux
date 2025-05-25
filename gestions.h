#ifndef GESTIONS_H
#define GESTIONS_H

#include <QDialog>

namespace Ui {
class gestions;
}

class gestions : public QDialog
{
    Q_OBJECT

public:
    explicit gestions(QWidget *parent = nullptr);
    ~gestions();

private slots:
    void on_emp_clicked();

private:
    Ui::gestions *ui;
};

#endif // GESTIONS_H
