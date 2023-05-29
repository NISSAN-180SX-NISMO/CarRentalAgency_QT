#include "historybase.h"

HistoryBase::HistoryBase(QObject *parent)
    : QObject{parent}
{
    for (int i = 0; i < 4; ++i)
        history.push_back(QVector<std::pair<Car*, Period>>{});
}


void HistoryBase::insert(Class clas, Car* car, Period period){
    this->history[int(clas)].push_back(std::pair<Car*,Period>(car, period));
}

QVector<std::pair<Car*, Period>> HistoryBase::getAll(){
    QVector<std::pair<Car*, Period>> all;
    for (auto& clas : history)
        for (auto &pair : clas)
            all.push_back(pair);
    return all;
}

QVector<std::pair<Car*, Period>> HistoryBase::getAll(Class clas){
    QVector<std::pair<Car*, Period>> all;
    for (auto &pair : this->history[int(clas)])
        all.push_back(pair);
    return all;
}


std::pair<Car*, Period> HistoryBase::find(QString number){
    for (auto& clas: history)
        for (auto &car : clas)
            if(car.first->getNumber() == number)
                return car;
    return std::pair<Car*, Period> (nullptr, Period::OneDay);
}

void HistoryBase::remove(QString number){
    for (auto& clas : history)
            for (auto &pair : clas)
                if (pair.first->getNumber() == number)
                    clas.erase(std::remove(clas.begin(), clas.end(), pair));
}
