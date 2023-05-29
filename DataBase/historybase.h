#ifndef HISTORYBASE_H
#define HISTORYBASE_H

#include "Atoms/Cars/car.h"
#include <QObject>
#include <QVector>
#include <QString>

class HistoryBase : public QObject
{
    Q_OBJECT
private:
    QVector<QVector<std::pair<Car*, Period>>> history;
public:
    explicit HistoryBase(QObject *parent = nullptr);
    void insert(Class clas, Car* car, Period period);
    QVector<std::pair<Car*, Period>> getAll();
    QVector<std::pair<Car*, Period>> getAll(Class clas);
    std::pair<Car*, Period> find(QString number);
    void remove(QString number);
signals:

};

#endif // HISTORYBASE_H
