#include "rentcurrentstate.h"
#include "qdebug.h"

// observer

RentCurrentState::RentCurrentState(QObject *parent)
    : QObject{parent}
{

}
RentCurrentState::~RentCurrentState(){

}

void RentCurrentState::changeClas(Class clas){
    this->clas = clas;
}

void RentCurrentState::changeSeverity(Severity sever){
    this->sever = sever;
}

void RentCurrentState::changeBrand(QString brand){
    this->brand = brand;
}

void RentCurrentState::changePeriod(Period period){
    this->period = period;
}

void RentCurrentState::changeNumber(QString number){
    this->number = number;
}


Car* RentCurrentState::getCar(){
    CarBuilder car;
    switch (clas){
    case Class::Business: return car.CreateBusiness().setNumber(number).setBrand(brand).getCar();
    case Class::Sport: return car.CreateSport().setNumber(number).setBrand(brand).getCar();
    case Class::OffRoad: return car.CreateOffRoad().setNumber(number).setBrand(brand).getCar();
    case Class::Electic: return car.CreateElectric().setNumber(number).setBrand(brand).getCar();
    }
}

Period RentCurrentState::getPeriod(){
    return this->period;
}

Severity RentCurrentState::getSeverity(){
    return this->sever;
}
