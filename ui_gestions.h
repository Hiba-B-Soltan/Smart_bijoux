/********************************************************************************
** Form generated from reading UI file 'gestions.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONS_H
#define UI_GESTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_gestions
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *emp;
    QPushButton *prof;

    void setupUi(QDialog *gestions)
    {
        if (gestions->objectName().isEmpty())
            gestions->setObjectName(QStringLiteral("gestions"));
        gestions->resize(562, 735);
        gestions->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/uuuuuuuuu.jpg);"));
        label = new QLabel(gestions);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 80, 411, 411));
        label->setStyleSheet(QStringLiteral("image: url(:/ooooo/iii.jpg);"));
        label_2 = new QLabel(gestions);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 480, 411, 411));
        label_2->setStyleSheet(QStringLiteral("image: url(:/ooooo/iii.jpg);"));
        emp = new QPushButton(gestions);
        emp->setObjectName(QStringLiteral("emp"));
        emp->setGeometry(QRect(260, 140, 111, 31));
        emp->setStyleSheet(QStringLiteral("background-color: rgb(237, 238, 240);"));
        prof = new QPushButton(gestions);
        prof->setObjectName(QStringLiteral("prof"));
        prof->setGeometry(QRect(200, 270, 101, 31));
        prof->setStyleSheet(QStringLiteral("background: rgb(236, 229, 221);"));

        retranslateUi(gestions);

        QMetaObject::connectSlotsByName(gestions);
    } // setupUi

    void retranslateUi(QDialog *gestions)
    {
        gestions->setWindowTitle(QApplication::translate("gestions", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        emp->setText(QApplication::translate("gestions", "Employee", Q_NULLPTR));
        prof->setText(QApplication::translate("gestions", "Produit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class gestions: public Ui_gestions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONS_H
