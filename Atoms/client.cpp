#include "client.h"

Client::Client()
{

}

Client::Client(QString passport, QString name)
{
    setPassport(passport);
    setName(name);
}

void Client::setPassport(QString passport){
    this->passport = passport;
}

void Client::setName(QString name){
    this->name = name;
}

QString Client::getPassport(){
    return this->passport;
}

QString Client::getName(){
    return this->name;
}


