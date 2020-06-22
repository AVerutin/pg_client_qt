#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->CreateDBConnection();
    this->CreateCentralWidget();

    this->setWindowTitle("Клиент PostgreSQL");
    this->setMinimumWidth(500);
    this->setMinimumHeight(480);
}

MainWindow::~MainWindow()
{
}

void MainWindow::CreateCentralWidget()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Nodes ORDER BY Id;");
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Наименование");
    model->setHeaderData(2, Qt::Horizontal, "Значение");
    tw->setModel(model);

    this->setCentralWidget(tw);
}

void MainWindow::CreateDBConnection()
{
    tw = new QTableView();
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.56.104");
    db.setPort(5432);
    db.setUserName("pguser");
    db.setDatabaseName("pguser");
    db.setPassword("pg_psswrd");
    if (!db.open())
    {
        QMessageBox::critical(this, "DB connection error", "Error connection to DB!");
    }
}
