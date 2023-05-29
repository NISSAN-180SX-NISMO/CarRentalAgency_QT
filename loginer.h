#pragma once
#ifndef LOGINER_H
#define LOGINER_H


#include "qdialog.h"
#include "ui_login.h"
#include <QWidget>

class LogIner : public QDialog
{
    Q_OBJECT
public:
    explicit LogIner(QDialog *parent = nullptr);
    ~LogIner() = default;
signals:

private slots:
    void on_EntrypushButton_clicked();

private:
    Ui::Dialog_LogIn* ui;
signals:
    void LogIn(QString passport);
};
#endif // LOGINER_H
