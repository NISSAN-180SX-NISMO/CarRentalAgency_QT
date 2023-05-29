#include "electric.h"

Electric::Electric()
{

}

void Electric::setNumber(QString number){
    this->number = number;
}

void Electric::setBrand(QString brand){
    this->brand = brand;
}

QString Electric::getNumber(){
    return this->number;
}

QString Electric::getBrand(){
    return this->brand;
}

int Electric::getRentCost(Period period){
    return this->FACTOR * int(period);
}

int Electric::getRepairCost(Severity severity){
    return this->FACTOR * 2 * int(severity);
}

Class Electric::getClass(){
    return Class::Electic;
}

