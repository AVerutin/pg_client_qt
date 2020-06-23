#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtSql>

#include "addlineparameter.h"
#include "tableviews.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CreateCentralWidget();
    void CreateDBConnection();
    void CreateMainMenu();
    void CreateForms();

    QSqlDatabase db;
    QTableView *tw;
    QSqlQuery *query;
    QSqlQueryModel *model;

    QMenu *menu;
    QAction *mnuGroups;
    QPushButton *runQuery;
    QLineEdit *leQuery;

    QVBoxLayout *form;
    QHBoxLayout *line1;
    QHBoxLayout *line2;

    // Вспомогательные формы
    addLineParameter *lineParameters;
    TableViews *tViews;

private slots:
    void newQueryAction();
};
#endif // MAINWINDOW_H
