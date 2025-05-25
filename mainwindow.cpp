#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QtSql>
#include <QtDebug>
#include <QMessageBox>
#include <QApplication>
#include <QMenu>
#include <QAction>
#include "statistique.h"
#include <QTextDocument>
#include <QPrinter>
#include <QTextCursor>
#include <QTextTable>
#include <QFileDialog>
#include <QSqlQueryModel>
#include "arduino.h"
#include "qrcode.h"
#include <QtSvg/QSvgRenderer>
#include <fstream>

int id=0,idd=0;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Id_produit->setValidator (new QIntValidator(0, 999999, this));
    ui->le_fournisseur->setValidator (new QIntValidator(0, 999999, this));
    ui->le_prix->setValidator (new QIntValidator(0, 99999, this));
    ui->le_poids->setValidator (new QIntValidator(0, 999, this));
    ui->le_quantite->setValidator (new QIntValidator(0, 99999, this));
    ui->tab_produit->setModel(pmp.afficher_produit());

    // Initialize the table model
    QSqlTableModel *tableModel = new QSqlTableModel(this);
    tableModel->setTable("PRODUIT");
    tableModel->select();

    // Set the table model to the QTableView
    ui->tab_view_mod->setModel(tableModel);
    ui->tab_view_mod->setEditTriggers(QAbstractItemView::DoubleClicked); // Enable editing on double-click
    ui->comboBox->addItem("Trier par Identifiant");
    ui->comboBox->addItem("Trier par Prix");
    ui->comboBox->addItem("Trier par Quantite");


    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(onComboBoxActivated(int)));
    connect(ui->le_rechercher, SIGNAL(returnPressed()), this, SLOT(onReturnPressed()));



    // *****Map*******
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/QmlMap.qml")));
    ui->quickWidget->show();

    auto Obje = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenterPosition(QVariant, QVariant)), Obje, SLOT(setCenterPosition(QVariant, QVariant)));
    emit setCenterPosition(36.8065, 10.1815);
    emit setLocationMarking(36.8065, 10.1815);
    //arduino
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug() << "arduino is available and connected to :"<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to:" <<A.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
    }
   // QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   int id_prduit=ui->le_Id_produit->text().toInt();
   int quantite=ui->le_quantite->text().toInt();
   float prix=ui->le_prix->text().toFloat();
   float poids=ui->le_poids->text().toFloat();
   int fournisseur=ui->le_fournisseur->text().toInt();
   QString materiaux=ui->le_materiaux->text();
   QString couleur=ui->le_couleur->text();

   Produit P(id_prduit,quantite,prix,poids,fournisseur,materiaux,couleur);
   bool test=P.ajouter_produit();

   if(test) // requete executee
   {
       updateTabViewMod();
       ui->tab_produit->setModel(pmp.afficher_produit());
       QMessageBox::information(nullptr,QObject::tr("ok"),
                    QObject::tr("Ajout effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                    QObject::tr("Ajout non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_supprimer_clicked()
{
    int id=ui->le_identifiant->text().toInt();
    bool test=pmp.supprimer_produit(id);
    if(test)
    {
        updateTabViewMod();
        ui->tab_produit->setModel(pmp.afficher_produit());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Suppression effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                     QObject::tr("Suppression non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_modifier_clicked()
{
   QSqlTableModel *tableModel = qobject_cast<QSqlTableModel*>(ui->tab_view_mod->model());

       if (tableModel) {

           if (tableModel->submitAll()) {
               ui->tab_produit->setModel(pmp.afficher_produit());
               QMessageBox::information(nullptr,QObject::tr("ok"),
                            QObject::tr("Modification effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);}

           else {QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                            QObject::tr("Modification non effectue.\n" "Click Cancel to exit."), QMessageBox::Cancel);}
       }

}
void MainWindow::updateTabViewMod()
{
    QSqlTableModel *tableModel = qobject_cast<QSqlTableModel*>(ui->tab_view_mod->model());
    if (tableModel) {
        tableModel->select();
    }
}

void MainWindow::onComboBoxActivated(int index) {

    QString selectedOption = ui->comboBox->itemText(index);

    if (selectedOption == "Trier par Identifiant") {
        QSqlQueryModel *sortedModel = pmp.trier_identifiant();
        if (sortedModel) {
            ui->tab_produit->setModel(sortedModel);}
    }

    if (selectedOption == "Trier par Prix") {
        QSqlQueryModel *sortedModel = pmp.trier_prix();
        if (sortedModel) {
            ui->tab_produit->setModel(sortedModel);}
    }

    else if (selectedOption == "Trier par Quantite") {
        QSqlQueryModel *sortedModel = pmp.trier_quantite();
        if (sortedModel) {
            ui->tab_produit->setModel(sortedModel);}
    }
}
void MainWindow::onReturnPressed()
{
    QString text = ui->le_rechercher->text(); // Get the text from the QLineEdit

    if (!text.isEmpty()) {
         int id=ui->le_rechercher->text().toInt();
        ui->tab_produit->setModel(pmp.recherche(id));
    } else {
         ui->tab_produit->setModel(pmp.afficher_produit());
    }

}


void MainWindow::on_chart1_clicked()
{
    qDebug() << "Button Clicked";
 // ChartWindow *chartWindow = new ChartWindow(this);

    // Create an instance of the chart handler
    statistique chartHandler;

    // Call the function to generate the pie chart and get the QChart instance
    QChart* chart = chartHandler.generatePieChart();

    // Get the chart view from the QChart instance
    QChartView *chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setChart(chart);

    // Set the chart view in the chart window
    QMainWindow *chartWindow = new QMainWindow();
       chartWindow->setCentralWidget(chartView);
       chartWindow->resize(420, 300);
    // Show the chart window
    chartWindow->show();
}

void MainWindow::on_pb_export_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QString(), "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return;  // L'utilisateur a annulé la sélection du fichier
    }

    // Créez le périphérique d'impression
    QPrinter printer(QPrinter::PrinterResolution);

    // Définissez le nom du fichier de sortie
    printer.setOutputFileName(fileName);
    printer.setOutputFormat(QPrinter::PdfFormat);

    // Créez un document QText pour contenir le contenu du PDF
    QTextDocument doc;

    // Créez un curseur pour ajouter du texte au document
    QTextCursor cursor(&doc);

    // Ajoutez un en-tête au document
    QTextCharFormat format;
    format.setFont(QFont("Arial", 16, QFont::Bold));
    cursor.insertText("Liste des Employés\n\n", format);

    // Obtenez le modèle de la table et parcourez les lignes pour ajouter les données au document
    QSqlQueryModel *model = new QSqlQueryModel();
    model = static_cast<QSqlQueryModel*>(ui->tab_produit->model());
    int rowCount = model->rowCount();
    int colCount = model->columnCount();

    // Créez une table pour afficher les données
    QTextTable *table = cursor.insertTable(rowCount + 1, colCount);

    // Remplissez la première ligne avec les noms de colonnes
    for (int col = 0; col < colCount; ++col) {
        table->cellAt(0, col).firstCursorPosition().insertText(model->headerData(col, Qt::Horizontal).toString());
    }

    // Remplissez le reste de la table avec les données de la base de données
    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < colCount; ++col) {
            table->cellAt(row + 1, col).firstCursorPosition().insertText(model->data(model->index(row, col)).toString());
        }
    }

    // Imprimez le document sur le périphérique d'impression
    doc.print(&printer);
    QMessageBox::information(this, "Export PDF", "Exportation en PDF réussie !");
}

/*void MainWindow::on_pb_QR_clicked()
{

    
        //generate pdf
        

        // Encode the fetched information as a QR Code
        const QrCode qr = QrCode::encodeText(generatedpdf.toStdString().c_str(), QrCode::Ecc::LOW);

        // Save the QR Code as an image
        QImage qrImage = QImage(qr.getSize(), qr.getSize(), QImage::Format_Mono);
        for (int y = 0; y < qr.getSize(); ++y) {
            for (int x = 0; x < qr.getSize(); ++x) {
                qrImage.setPixel(x, y, qr.getModule(x, y) ? 0 : 1);
            }
        }
        // Display the QR Code image in a QLabel
           ui->QRCODE_3->setPixmap(QPixmap::fromImage(qrImage));
}*/
//Arduino

void MainWindow::on_pb_on_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_pb_off_clicked()
{
    A.write_to_arduino("2");
}

