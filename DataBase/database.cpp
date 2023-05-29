#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject{parent}
{
for (int i = 0; i < 4; ++i)
    cars.push_back(QVector<Car*>{});
}

void DataBase::insert(Class clas, Car* car){
    cars[int(clas)].push_back(car);
}

void DataBase::remove(QString number){
    for (auto &clas : this->cars)
        for (auto& car : clas)
            if (car->getNumber() == number)
                clas.erase(std::remove(clas.begin(), clas.end(), car));
}

Car* DataBase::find(QString number){
    for (auto& clas: cars)
        for (auto &car : clas)
            if(car->getNumber() == number)
                return car;
    return nullptr;
}

QVector<Car*> DataBase::find(Class clas, QString brand){
    QVector<Car*> all;
    for (auto &car : cars[int(clas)])
        if(car->getBrand() == brand)
            all.push_back(car);
    return all;
}

QVector<Car*> DataBase::find(Class clas){
    return this->cars[int(clas)];
}

QVector<Car*> DataBase::getAll(Class clas){
    QVector<Car*> all;
    for(auto &car : cars[int(clas)])
        all.push_back(car);
    return all;
}
