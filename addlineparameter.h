#ifndef ADDLINEPARAMETER_H
#define ADDLINEPARAMETER_H

#include <QDialog>
#include <QtWidgets>

class addLineParameter : public QDialog
{
    Q_OBJECT
public:
    QVBoxLayout *form;
    QHBoxLayout *nameLine;
    QHBoxLayout *buttonsLine;
    QLabel *lblName;
    QLineEdit *leName;
    QPushButton *pbOk;
    QPushButton *pbCancel;

    explicit addLineParameter(QWidget *parent = nullptr, QString title = "Новый элемент");
    void createCentralWidget(QString);
    void setCaption(QString);
    void setDefaultValue(QString);
    QString getValue();


private:
    QString strValue;

private slots:
    void onClick_Ok();
    void onClick_Cancel();

};

#endif // ADDLINEPARAMETER_H

