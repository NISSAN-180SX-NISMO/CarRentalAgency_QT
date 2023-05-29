#include "carbuilder.h"

CarBuilder::CarBuilder()
{

}


CarBuilder CarBuilder::CreateBusiness(){
    this->current = new Business;
    return *this;
}

CarBuilder CarBuilder::CreateSport(){
    this->current = new Sport;
    return *this;
}

CarBuilder CarBuilder::CreateOffRoad(){
    this->current = new OffRoad;
    return *this;
}

CarBuilder CarBuilder::CreateElectric(){
    this->current = new Electric;
    return *this;
}

CarBuilder CarBuilder::setNumber(QString number){
    this->current->setNumber(number);
    return *this;
}

CarBuilder CarBuilder::setBrand(QString brand){
    this->current->setBrand(brand);
    return *this;
}

Car* CarBuilder::getCar(){
    return this->current;
}
