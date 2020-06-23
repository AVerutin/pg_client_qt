#include "tableviews.h"

TableViews::TableViews()
{
    model = new QSqlQueryModel;
    tw = new QTableView;
    form = new QVBoxLayout;

    form->addWidget(tw);

    tw->setModel(model);
    this->setLayout(form);
}

void TableViews::setCaption(QString title)
{
    if (title != "")
    {
        setWindowTitle(title);
    }
}

void TableViews::setQuery(QString query)
{
    if (query != "")
    {
        model->setQuery(query);
    }
}
