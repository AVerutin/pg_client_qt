#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    CreateDBConnection();
    CreateCentralWidget();
    CreateMainMenu();
    CreateForms();

    connect(newQuery, &QAction::triggered, this, &MainWindow::newQueryAction);
}

MainWindow::~MainWindow()
{
}

void MainWindow::CreateCentralWidget()
{
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM PQCA.Contragents ORDER BY Id;");
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Имя");
    model->setHeaderData(2, Qt::Horizontal, "Должность");
    model->setHeaderData(3, Qt::Horizontal, "Инициалы");
    model->setHeaderData(4, Qt::Horizontal, "Внешний");
    tw->setModel(model);

    setCentralWidget(tw);
    setWindowTitle("Клиент PostgreSQL");
    setMinimumWidth(550);
    setMinimumHeight(480);
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

void MainWindow::CreateMainMenu()
{
    menu = menuBar()->addMenu("&Справочники");
    mnuGroups = new QAction("Группы элементов");
    menu->addAction(mnuGroups);

}

void MainWindow::newQueryAction()
{
//    lineParameters->exec();
    tViews->exec();
}

void MainWindow::CreateForms()
{
//    lineParameters = new addLineParameter(this);
//    lineParameters->setCaption("Добавить химический элемент");

    tViews = new TableViews();
    tViews->setCaption("Справочник групп");
    tViews->setQuery("SELECT * FROM pqca.Groups ORDER BY Id");
}
