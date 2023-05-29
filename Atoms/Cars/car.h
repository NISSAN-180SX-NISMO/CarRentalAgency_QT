#ifndef CAR_H
#define CAR_H
#include <QString>

enum class Class {
    Business,
    Sport,
    OffRoad,
    Electic
};

enum class Period {
    OneDay = 1,
    TwoDay = 2,
    ThreeDay = 3,
    OneWeek = 7,
    TwoWeek = 14
};

enum class Severity {
    None = 0,
    Small = 1,
    Middle = 2,
    High = 3
};

class Car       // паттерн Прототип
{
protected:
    QString number;
    QString brand;
public:
    Car();
    virtual void setNumber(QString number) = 0;
    virtual void setBrand(QString brand) = 0;
    virtual QString getNumber() = 0;
    virtual QString getBrand() = 0;
    virtual int getRentCost(Period) = 0;
    virtual int getRepairCost(Severity) = 0;
    virtual Class getClass() = 0;
};

#endif // CAR_H
