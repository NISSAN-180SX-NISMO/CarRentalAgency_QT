#ifndef RENTCURRENTSTATE_H
#define RENTCURRENTSTATE_H
#include <QString>
#include <QObject>
#include "Cars/car.h"
#include "Builders/carbuilder.h"

class RentCurrentState: public QObject
{
    Q_OBJECT
private:
    Class clas;
    Period period;
    Severity sever;
    QString brand;
    QString number;
public:
    explicit RentCurrentState(QObject *parent = nullptr);
    ~RentCurrentState();

    Car* getCar();
public slots:
    void changeClas(Class);
    void changePeriod(Period);
    void changeSeverity(Severity);
    void changeBrand(QString);
    void changeNumber(QString);
    Period getPeriod();
    Severity getSeverity();
};

#endif // RENTCURRENTSTATE_H
