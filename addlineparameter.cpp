#include "addlineparameter.h"

addLineParameter::addLineParameter(QWidget *parent, QString title) : QDialog(parent)
{
    createCentralWidget(title);

    connect(pbOk, &QPushButton::clicked, this, &addLineParameter::onClick_Ok);
    connect(pbCancel, &QPushButton::clicked, this, &addLineParameter::onClick_Cancel);

}

void addLineParameter::createCentralWidget(QString title)
{
    nameLine = new QHBoxLayout;
    buttonsLine = new QHBoxLayout;
    form = new QVBoxLayout;
    lblName = new QLabel("Наименование");
    leName = new QLineEdit;
    pbOk = new QPushButton("OK");
    pbCancel = new QPushButton("Отмена");
    leName->setText(strValue);

    nameLine->addWidget(lblName);
    nameLine->addWidget(leName);
    buttonsLine->addStretch();
    buttonsLine->addWidget(pbOk);
    buttonsLine->addWidget(pbCancel);
    buttonsLine->addStretch();

    form->addLayout(nameLine);
    form->addStretch();
    form->addLayout(buttonsLine);

    setWindowTitle(title);
    setMinimumSize(430, 90);
    setMaximumSize(430, 90);
    setLayout(form);
}

void addLineParameter::setCaption(QString caption)
{
    if (caption != "")
    {
        setWindowTitle(caption);
    }
    else
    {
        setWindowTitle("Новое значение");
    }
}

void addLineParameter::setDefaultValue(QString value)
{
    strValue = value;
}

QString addLineParameter::getValue()
{
    return strValue;
}

void addLineParameter::onClick_Ok()
{
    strValue = leName->text();
    hide();
}

void addLineParameter::onClick_Cancel()
{
    leName->setText("");
    hide();
}
