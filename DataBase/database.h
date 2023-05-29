#ifndef DATABASE_H
#define DATABASE_H

#include "Atoms/Cars/car.h"
#include <QObject>
#include <QVector>
#include <QString>

class DataBase : public QObject
{
    Q_OBJECT
private:
    QVector<QVector<Car*>> cars;
public:
    explicit DataBase(QObject *parent = nullptr);
    void insert(Class clas, Car* car);
    void remove(QString number);
    Car* find(QString number);
    QVector<Car*> find(Class clas, QString brand);
    QVector<Car*> find(Class clas);
    QVector<Car*> getAll(Class clas);
signals:

};

#endif // DATABASE_H
