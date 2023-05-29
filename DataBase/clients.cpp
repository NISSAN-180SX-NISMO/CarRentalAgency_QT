#include "clients.h"

Clients::Clients(QObject *parent)
    : QObject{parent}
{

}

void Clients::registClient(Client* current){
    this->allClients.push_back(current);
}

Client* Clients::find(QString passport){
    auto finded = std::find_if(this->allClients.begin(),
                         this->allClients.end(),
                         [passport](Client* current){
        return current->getPassport() == passport;
    });
    return finded == allClients.end() ? nullptr : *finded;
}
