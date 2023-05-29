#ifndef SPORT_H
#define SPORT_H

#include "car.h"

class Sport : public Car
{
private:
    const int FACTOR = 3500;
public:
    Sport();
    virtual void setNumber(QString number) override;
    virtual void setBrand(QString brand) override;
    virtual QString getNumber() override;
    virtual QString getBrand() override;
    virtual int getRentCost(Period) override;
    virtual int getRepairCost(Severity) override;
    virtual Class getClass() override;
};

#endif // SPORT_H
