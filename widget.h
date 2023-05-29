#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Atoms/rentcurrentstate.h"
#include "DataBase/clients.h"
#include "DataBase/database.h"
#include "appstate.h"
#include "registrator.h"
#include "loginer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Class_comboBox_activated(int index);

    void on_Brand_comboBox_activated(int index);

    void on_Period_comboBox_activated(int index);

    void on_Number_comboBox_activated(int index);

    void on_Payment_checkBox_stateChanged(int arg1);

    void on_RegistClientButton_clicked();

    void on_EntryClientButton_clicked();

    void on_ExitClientButton_clicked();

    void on_Issue_pushButton_clicked();

    void on_ReturnpushButton_clicked();

    void on_checkBox_2_stateChanged(int arg1);



    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::Widget *ui;
    Registrator* reg;
    LogIner* login;
    RentCurrentState info;
    DataBase DB;
    Clients clients;
    Client* currentClient;
    void showAllCars();
    void showAllClients();
    void showCurrentClient();
    void showClientsHistory(QString passport);
    void _init ();
    void update();
public slots:
    void registed(QString passport, QString name);
    void logined(QString passport);

    void getBrands(Class clas);
    void getNumbers(QString brand);
    void getRentCost();
    void getRepairCost();
signals:
    void ClasChanged(Class);
    void BrandChanged(QString);
    void PeriodChanged(Period);
    void NumberChanged(QString);
    void SeverityChanged(Severity);
};
#endif // WIDGET_H
