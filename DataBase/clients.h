#ifndef CLIENTS_H
#define CLIENTS_H

#include "Atoms/client.h"
#include <QObject>

class Clients : public QObject
{
    Q_OBJECT
public:
    QVector<Client*> allClients;
    QVector<Client*> debtors;

    explicit Clients(QObject *parent = nullptr);
    void registClient(Client* client);
    bool removeClient(QString passport);
    void setDebtor(QString passport);
    void removeDebtor(QString passport);
    Client* find(QString passport);
signals:

};

#endif // CLIENTS_H
