#include "business.h"

Business::Business()
{

}

void Business::setNumber(QString number){
    this->number = number;
}

void Business::setBrand(QString brand){
    this->brand = brand;
}

QString Business::getNumber(){
    return this->number;
}

QString Business::getBrand(){
    return this->brand;
}

int Business::getRentCost(Period period){
    return this->FACTOR * int(period);
}

int Business::getRepairCost(Severity severity){
    return this->FACTOR * 2 * int(severity);
}

Class Business::getClass(){
    return Class::Business;
}
