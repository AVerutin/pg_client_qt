#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QtSql>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void CreateCentralWidget();
    void CreateDBConnection();

    QSqlDatabase db;
    QTableView *tw;
    QSqlQuery *query;
    QSqlQueryModel *model;

    QMenu *menu;
    QAction *newQuery;
    QPushButton *runQuery;
    QLineEdit *leQuery;

    QVBoxLayout *form;
    QHBoxLayout *line1;
    QHBoxLayout *line2;
};
#endif // MAINWINDOW_H
