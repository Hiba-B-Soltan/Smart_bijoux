/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_6;
    QTableView *tab_affiche;
    QComboBox *combo_tri;
    QWidget *tab_7;
    QGroupBox *groupBox_6;
    QLineEdit *saisir_id;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLineEdit *li_id;
    QLineEdit *li_nom;
    QLineEdit *li_prenom;
    QLineEdit *li_adresse;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLineEdit *li_titre;
    QLineEdit *li_departement;
    QLineEdit *li_performance;
    QLineEdit *li_langue;
    QDateEdit *li_date;
    QLabel *label_41;
    QLineEdit *li_sexe;
    QLabel *label_42;
    QPushButton *bt_modifier;
    QPushButton *bt_chercher;
    QGroupBox *groupBox_7;
    QLabel *label_10;
    QLineEdit *le_id_supprimer;
    QPushButton *bt_supperimer;
    QPushButton *chart1;
    QPushButton *bt_export_pdf;
    QLabel *label_8;
    QLineEdit *le_langue;
    QLabel *label_3;
    QLineEdit *le_prenom;
    QLineEdit *le_titre;
    QLabel *label_6;
    QLabel *label_24;
    QLineEdit *le_mail;
    QLineEdit *le_performance;
    QLineEdit *le_departement;
    QComboBox *combo_sexe;
    QLineEdit *le_nom;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_2;
    QDateEdit *le_date;
    QLineEdit *le_id;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_23;
    QLineEdit *le_rf;
    QLabel *label_44;
    QLineEdit *le_question;
    QLabel *label_26;
    QLineEdit *le_passe;
    QPushButton *bt_ajouter;
    QLabel *label_27;
    QLineEdit *le_rep;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1891, 976);
        Dialog->setStyleSheet(QStringLiteral("background-image: url(:/background/ccccccc (7).png);"));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(950, 10, 931, 261));
        tabWidget->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tab_affiche = new QTableView(tab_6);
        tab_affiche->setObjectName(QStringLiteral("tab_affiche"));
        tab_affiche->setGeometry(QRect(0, 20, 921, 211));
        tab_affiche->setStyleSheet(QStringLiteral("background-color: rgb(252, 248, 242);"));
        combo_tri = new QComboBox(tab_6);
        combo_tri->setObjectName(QStringLiteral("combo_tri"));
        combo_tri->setGeometry(QRect(10, 10, 201, 31));
        combo_tri->setStyleSheet(QStringLiteral("background: rgb(237, 228, 207);"));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        groupBox_6 = new QGroupBox(tab_7);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, -60, 971, 401));
        groupBox_6->setStyleSheet(QLatin1String("\n"
"background-color: rgb(252, 248, 241);"));
        saisir_id = new QLineEdit(groupBox_6);
        saisir_id->setObjectName(QStringLiteral("saisir_id"));
        saisir_id->setGeometry(QRect(340, 100, 191, 31));
        label_31 = new QLabel(groupBox_6);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(560, 160, 56, 16));
        QFont font;
        font.setPointSize(10);
        label_31->setFont(font);
        label_32 = new QLabel(groupBox_6);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(10, 240, 56, 16));
        label_32->setFont(font);
        label_33 = new QLabel(groupBox_6);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(10, 280, 71, 20));
        label_33->setFont(font);
        label_34 = new QLabel(groupBox_6);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(20, 340, 56, 16));
        label_34->setFont(font);
        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(300, 170, 56, 16));
        label_35->setFont(font);
        li_id = new QLineEdit(groupBox_6);
        li_id->setObjectName(QStringLiteral("li_id"));
        li_id->setGeometry(QRect(100, 170, 121, 31));
        li_nom = new QLineEdit(groupBox_6);
        li_nom->setObjectName(QStringLiteral("li_nom"));
        li_nom->setGeometry(QRect(620, 160, 121, 31));
        li_prenom = new QLineEdit(groupBox_6);
        li_prenom->setObjectName(QStringLiteral("li_prenom"));
        li_prenom->setGeometry(QRect(100, 230, 121, 31));
        li_adresse = new QLineEdit(groupBox_6);
        li_adresse->setObjectName(QStringLiteral("li_adresse"));
        li_adresse->setGeometry(QRect(100, 280, 121, 31));
        label_36 = new QLabel(groupBox_6);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(290, 130, 56, 16));
        label_37 = new QLabel(groupBox_6);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(10, 170, 81, 20));
        label_37->setFont(font);
        label_38 = new QLabel(groupBox_6);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(280, 270, 51, 41));
        label_38->setFont(font);
        label_39 = new QLabel(groupBox_6);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(240, 230, 111, 16));
        label_39->setFont(font);
        label_40 = new QLabel(groupBox_6);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(520, 230, 111, 16));
        label_40->setFont(font);
        li_titre = new QLineEdit(groupBox_6);
        li_titre->setObjectName(QStringLiteral("li_titre"));
        li_titre->setGeometry(QRect(360, 160, 131, 31));
        li_departement = new QLineEdit(groupBox_6);
        li_departement->setObjectName(QStringLiteral("li_departement"));
        li_departement->setGeometry(QRect(360, 220, 131, 31));
        li_performance = new QLineEdit(groupBox_6);
        li_performance->setObjectName(QStringLiteral("li_performance"));
        li_performance->setGeometry(QRect(620, 220, 131, 31));
        li_langue = new QLineEdit(groupBox_6);
        li_langue->setObjectName(QStringLiteral("li_langue"));
        li_langue->setGeometry(QRect(360, 270, 131, 31));
        li_date = new QDateEdit(groupBox_6);
        li_date->setObjectName(QStringLiteral("li_date"));
        li_date->setGeometry(QRect(100, 330, 131, 31));
        label_41 = new QLabel(groupBox_6);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(280, 340, 56, 16));
        QFont font1;
        font1.setPointSize(11);
        label_41->setFont(font1);
        li_sexe = new QLineEdit(groupBox_6);
        li_sexe->setObjectName(QStringLiteral("li_sexe"));
        li_sexe->setGeometry(QRect(360, 340, 121, 31));
        label_42 = new QLabel(groupBox_6);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(170, 110, 131, 16));
        label_42->setFont(font);
        bt_modifier = new QPushButton(groupBox_6);
        bt_modifier->setObjectName(QStringLiteral("bt_modifier"));
        bt_modifier->setGeometry(QRect(650, 300, 131, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        bt_modifier->setFont(font2);
        bt_chercher = new QPushButton(groupBox_6);
        bt_chercher->setObjectName(QStringLiteral("bt_chercher"));
        bt_chercher->setGeometry(QRect(600, 90, 93, 28));
        tabWidget->addTab(tab_7, QString());
        groupBox_7 = new QGroupBox(Dialog);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(1350, 280, 501, 231));
        groupBox_7->setStyleSheet(QLatin1String("\n"
"background: rgb(255, 255, 255);"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 30, 251, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral("background: rgb(252, 248, 242);"));
        le_id_supprimer = new QLineEdit(groupBox_7);
        le_id_supprimer->setObjectName(QStringLiteral("le_id_supprimer"));
        le_id_supprimer->setGeometry(QRect(100, 80, 161, 31));
        bt_supperimer = new QPushButton(groupBox_7);
        bt_supperimer->setObjectName(QStringLiteral("bt_supperimer"));
        bt_supperimer->setGeometry(QRect(210, 140, 141, 41));
        bt_supperimer->setFont(font2);
        bt_supperimer->setStyleSheet(QStringLiteral("background: rgb(252, 248, 242);"));
        chart1 = new QPushButton(Dialog);
        chart1->setObjectName(QStringLiteral("chart1"));
        chart1->setGeometry(QRect(1760, 680, 121, 51));
        chart1->setFont(font1);
        bt_export_pdf = new QPushButton(Dialog);
        bt_export_pdf->setObjectName(QStringLiteral("bt_export_pdf"));
        bt_export_pdf->setGeometry(QRect(1760, 620, 121, 51));
        bt_export_pdf->setFont(font1);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 410, 121, 21));
        QFont font3;
        font3.setFamily(QStringLiteral("MV Boli"));
        font3.setPointSize(12);
        label_8->setFont(font3);
        label_8->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        le_langue = new QLineEdit(Dialog);
        le_langue->setObjectName(QStringLiteral("le_langue"));
        le_langue->setGeometry(QRect(170, 450, 131, 31));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 140, 81, 31));
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        le_prenom = new QLineEdit(Dialog);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(170, 140, 131, 31));
        le_titre = new QLineEdit(Dialog);
        le_titre->setObjectName(QStringLiteral("le_titre"));
        le_titre->setGeometry(QRect(170, 300, 131, 31));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 310, 111, 21));
        label_6->setFont(font3);
        label_6->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label_24 = new QLabel(Dialog);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(100, 250, 56, 31));
        label_24->setFont(font3);
        label_24->setStyleSheet(QLatin1String("background: rgb(255, 255, 255);\n"
""));
        le_mail = new QLineEdit(Dialog);
        le_mail->setObjectName(QStringLiteral("le_mail"));
        le_mail->setGeometry(QRect(170, 190, 131, 31));
        le_performance = new QLineEdit(Dialog);
        le_performance->setObjectName(QStringLiteral("le_performance"));
        le_performance->setGeometry(QRect(170, 400, 131, 31));
        le_departement = new QLineEdit(Dialog);
        le_departement->setObjectName(QStringLiteral("le_departement"));
        le_departement->setGeometry(QRect(170, 350, 131, 31));
        combo_sexe = new QComboBox(Dialog);
        combo_sexe->setObjectName(QStringLiteral("combo_sexe"));
        combo_sexe->setGeometry(QRect(170, 240, 131, 31));
        le_nom = new QLineEdit(Dialog);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(170, 90, 131, 31));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 200, 71, 16));
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 101, 20));
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 460, 111, 20));
        QFont font4;
        font4.setFamily(QStringLiteral("MV Boli"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        label_9->setFont(font4);
        label_9->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 90, 41, 16));
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        le_date = new QDateEdit(Dialog);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setGeometry(QRect(170, 500, 141, 31));
        le_id = new QLineEdit(Dialog);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(170, 40, 131, 31));
        le_id->setStyleSheet(QStringLiteral("alternate-background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 350, 111, 21));
        QFont font5;
        font5.setFamily(QStringLiteral("MV Boli"));
        font5.setPointSize(11);
        label_7->setFont(font5);
        label_7->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 510, 131, 20));
        label_5->setFont(font5);
        label_5->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        label_23 = new QLabel(Dialog);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(30, 570, 121, 16));
        label_23->setFont(font5);
        label_23->setStyleSheet(QStringLiteral("background: rgb(255, 255, 255);"));
        le_rf = new QLineEdit(Dialog);
        le_rf->setObjectName(QStringLiteral("le_rf"));
        le_rf->setGeometry(QRect(170, 600, 131, 31));
        label_44 = new QLabel(Dialog);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(110, 620, 56, 16));
        label_44->setFont(font3);
        le_question = new QLineEdit(Dialog);
        le_question->setObjectName(QStringLiteral("le_question"));
        le_question->setGeometry(QRect(90, 680, 241, 31));
        label_26 = new QLabel(Dialog);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(70, 650, 291, 20));
        label_26->setFont(font3);
        le_passe = new QLineEdit(Dialog);
        le_passe->setObjectName(QStringLiteral("le_passe"));
        le_passe->setGeometry(QRect(170, 550, 131, 31));
        bt_ajouter = new QPushButton(Dialog);
        bt_ajouter->setObjectName(QStringLiteral("bt_ajouter"));
        bt_ajouter->setGeometry(QRect(170, 790, 101, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Rockwell Extra Bold"));
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setWeight(75);
        bt_ajouter->setFont(font6);
        bt_ajouter->setStyleSheet(QString::fromUtf8("background-image: url(:/\331\204\330\256\331\205\331\212/\330\256\330\256\330\256\330\256.jpg);"));
        label_27 = new QLabel(Dialog);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(70, 720, 221, 21));
        label_27->setFont(font3);
        le_rep = new QLineEdit(Dialog);
        le_rep->setObjectName(QStringLiteral("le_rep"));
        le_rep->setGeometry(QRect(100, 750, 241, 31));

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Dialog", "Tab 1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Dialog", "Modification+Recherche", Q_NULLPTR));
        label_31->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_32->setText(QApplication::translate("Dialog", "Prenom", Q_NULLPTR));
        label_33->setText(QApplication::translate("Dialog", "Adresse", Q_NULLPTR));
        label_34->setText(QApplication::translate("Dialog", "Date", Q_NULLPTR));
        label_35->setText(QApplication::translate("Dialog", "Titre", Q_NULLPTR));
        label_36->setText(QString());
        label_37->setText(QApplication::translate("Dialog", "identifiant", Q_NULLPTR));
        label_38->setText(QApplication::translate("Dialog", "langue", Q_NULLPTR));
        label_39->setText(QApplication::translate("Dialog", "Departement", Q_NULLPTR));
        label_40->setText(QApplication::translate("Dialog", "Performance", Q_NULLPTR));
        label_41->setText(QApplication::translate("Dialog", "sexe", Q_NULLPTR));
        label_42->setText(QApplication::translate("Dialog", "Saisir l'identifiant", Q_NULLPTR));
        bt_modifier->setText(QApplication::translate("Dialog", "Modifier", Q_NULLPTR));
        bt_chercher->setText(QApplication::translate("Dialog", "chercher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("Dialog", "Tab 2", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Dialog", "Suppression ", Q_NULLPTR));
        label_10->setText(QApplication::translate("Dialog", "Inserrer l'identifiant de l'employ\303\251", Q_NULLPTR));
        bt_supperimer->setText(QApplication::translate("Dialog", "Supprimer", Q_NULLPTR));
        chart1->setText(QApplication::translate("Dialog", "statestique", Q_NULLPTR));
        bt_export_pdf->setText(QApplication::translate("Dialog", "Export PDF", Q_NULLPTR));
        label_8->setText(QApplication::translate("Dialog", "performance", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "prenom", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "titre_poste", Q_NULLPTR));
        label_24->setText(QApplication::translate("Dialog", "sexe", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "e_mail", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "identifiant", Q_NULLPTR));
        label_9->setText(QApplication::translate("Dialog", "langue_parlee", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "nom", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "departement", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "date_embauche", Q_NULLPTR));
        label_23->setText(QApplication::translate("Dialog", "Mot de passe", Q_NULLPTR));
        label_44->setText(QApplication::translate("Dialog", "rfid", Q_NULLPTR));
        label_26->setText(QApplication::translate("Dialog", "Entrer votre question secrete", Q_NULLPTR));
        bt_ajouter->setText(QApplication::translate("Dialog", "Ajouter", Q_NULLPTR));
        label_27->setText(QApplication::translate("Dialog", "Entrer votre reponse ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
