#ifndef ELECTRIC_H
#define ELECTRIC_H

#include "car.h"

class Electric : public Car
{
private:
    const int FACTOR = 2500;
public:
    Electric();
    virtual void setNumber(QString number) override;
    virtual void setBrand(QString brand) override;
    virtual QString getNumber() override;
    virtual QString getBrand() override;
    virtual int getRentCost(Period) override;
    virtual int getRepairCost(Severity) override;
    virtual Class getClass() override;
};

#endif // ELECTRIC_H
