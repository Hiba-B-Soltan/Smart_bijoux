/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_43;
    QGroupBox *groupBox_5;
    QLineEdit *la_identifiant;
    QLineEdit *la_passe;
    QPushButton *connexion;
    QPushButton *oublier;
    QCheckBox *checkBoxAfficherMotDePasse;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuLOGIN;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(515, 503);
        MainWindow->setStyleSheet(QStringLiteral("background-image: url(:/background/ccccccc (7).png);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_43 = new QLabel(centralWidget);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(1720, 550, 91, 81));
        label_43->setStyleSheet(QStringLiteral("image: url(:/bt/lllll.PNG);"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(-40, -80, 2061, 791));
        groupBox_5->setStyleSheet(QStringLiteral("background-image: url(:/bt/uuu.jpg);"));
        la_identifiant = new QLineEdit(groupBox_5);
        la_identifiant->setObjectName(QStringLiteral("la_identifiant"));
        la_identifiant->setGeometry(QRect(200, 240, 201, 41));
        la_passe = new QLineEdit(groupBox_5);
        la_passe->setObjectName(QStringLiteral("la_passe"));
        la_passe->setGeometry(QRect(200, 290, 201, 41));
        connexion = new QPushButton(groupBox_5);
        connexion->setObjectName(QStringLiteral("connexion"));
        connexion->setGeometry(QRect(230, 410, 111, 21));
        QFont font;
        font.setPointSize(10);
        connexion->setFont(font);
        connexion->setStyleSheet(QLatin1String("background-color: rgb(107, 116, 131);\n"
"color: rgb(255, 255, 255);"));
        oublier = new QPushButton(groupBox_5);
        oublier->setObjectName(QStringLiteral("oublier"));
        oublier->setGeometry(QRect(180, 470, 211, 21));
        QFont font1;
        font1.setPointSize(9);
        oublier->setFont(font1);
        oublier->setStyleSheet(QLatin1String("background-color: rgb(160, 225, 255);\n"
"color: rgb(255, 255, 255);"));
        checkBoxAfficherMotDePasse = new QCheckBox(groupBox_5);
        checkBoxAfficherMotDePasse->setObjectName(QStringLiteral("checkBoxAfficherMotDePasse"));
        checkBoxAfficherMotDePasse->setGeometry(QRect(410, 300, 16, 20));
        QFont font2;
        font2.setPointSize(11);
        checkBoxAfficherMotDePasse->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 515, 26));
        menuLOGIN = new QMenu(menuBar);
        menuLOGIN->setObjectName(QStringLiteral("menuLOGIN"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuLOGIN->menuAction());
        menuLOGIN->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_43->setText(QString());
        groupBox_5->setTitle(QString());
        connexion->setText(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
        oublier->setText(QApplication::translate("MainWindow", "MOT DE PASSE OUBLIER", Q_NULLPTR));
        checkBoxAfficherMotDePasse->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        menuLOGIN->setTitle(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
