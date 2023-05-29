#ifndef OFFROAD_H
#define OFFROAD_H

#include "car.h"

class OffRoad : public Car
{
private:
    const int FACTOR = 3000;
public:
    OffRoad();
    virtual void setNumber(QString number) override;
    virtual void setBrand(QString brand) override;
    virtual QString getNumber() override;
    virtual QString getBrand() override;
    virtual int getRentCost(Period) override;
    virtual int getRepairCost(Severity) override;
    virtual Class getClass() override;
};

#endif // OFFROAD_H
