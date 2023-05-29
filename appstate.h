#ifndef APPSTATE_H
#define APPSTATE_H

#include "ui_widget.h"
#include "Atoms/client.h"
#include <QWidget>
#include <QString>

class AppState : public QWidget
{
    Q_OBJECT

public:
    static bool inAccountNow;
    explicit AppState(QWidget *parent = nullptr);
    static void inAccount(Ui::Widget* ui, Client* current);
    static void choiceClient(Ui::Widget* ui, Client* current);
signals:

};


#endif // APPSTATE_H
