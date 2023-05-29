#include "sport.h"

Sport::Sport()
{

}

void Sport::setNumber(QString number){
    this->number = number;
}

void Sport::setBrand(QString brand){
    this->brand = brand;
}

QString Sport::getNumber(){
    return this->number;
}

QString Sport::getBrand(){
    return this->brand;
}

int Sport::getRentCost(Period period){
    return this->FACTOR * int(period);
}

int Sport::getRepairCost(Severity severity){
    return this->FACTOR * 2 * int(severity);
}

Class Sport::getClass(){
    return Class::Sport;
}

