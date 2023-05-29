#ifndef CARBUILDER_H
#define CARBUILDER_H
#include "Atoms/Cars/car.h"
#include "Atoms/Cars/business.h"
#include "Atoms/Cars/sport.h"
#include "Atoms/Cars/offroad.h"
#include "Atoms/Cars/electric.h"

class CarBuilder
{
private:
    Car* current;
public:
    CarBuilder();
    CarBuilder CreateBusiness();
    CarBuilder CreateSport();
    CarBuilder CreateOffRoad();
    CarBuilder CreateElectric();
    CarBuilder setNumber(QString number);
    CarBuilder setBrand(QString brand);

    Car* getCar();
};

#endif // CARBUILDER_H
