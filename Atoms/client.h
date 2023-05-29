#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QVector>
#include "Cars/car.h"
#include "DataBase/historybase.h"

class Client
{
private:
    QString passport;
    QString name;
public:
    HistoryBase history;
    HistoryBase inRent;
    Client();
    Client(QString passport, QString name);
    void setPassport(QString passport);
    void setName(QString name);
    QString getPassport();
    QString getName();
};

#endif // CLIENT_H
