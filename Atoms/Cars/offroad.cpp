#include "offroad.h"

OffRoad::OffRoad()
{

}

void OffRoad::setNumber(QString number){
    this->number = number;
}

void OffRoad::setBrand(QString brand){
    this->brand = brand;
}

QString OffRoad::getNumber(){
    return this->number;
}

QString OffRoad::getBrand(){
    return this->brand;
}

int OffRoad::getRentCost(Period period){
    return this->FACTOR * int(period);
}

int OffRoad::getRepairCost(Severity severity){
    return this->FACTOR * 2 * int(severity);
}

Class OffRoad::getClass(){
    return Class::OffRoad;
}
