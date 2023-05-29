#ifndef BUSINESS_H
#define BUSINESS_H

#include "car.h"

class Business : public Car
{
private:
    const int FACTOR = 4000;
public:
    Business();
    virtual void setNumber(QString number) override;
    virtual void setBrand(QString brand) override;
    virtual QString getNumber() override;
    virtual QString getBrand() override;
    virtual int getRentCost(Period) override;
    virtual int getRepairCost(Severity) override;
    virtual Class getClass() override;

};

#endif // BUSINESS_H
