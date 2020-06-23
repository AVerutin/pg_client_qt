#ifndef TABLEVIEWS_H
#define TABLEVIEWS_H

#include <QWidget>
#include <QtWidgets>
#include <QtSql>

class TableViews : public QDialog
{
    Q_OBJECT
public:
    QTableView *tw;
    QSqlQueryModel *model;
    QVBoxLayout *form;

    TableViews();
    void setCaption(QString);
    void setQuery(QString);
};

#endif // TABLEVIEWS_H
