#ifndef REGISTRATOR_H
#define REGISTRATOR_H

#include "ui_regist.h"
#include <QWidget>
#include "qregularexpression.h"

class Registrator : public QDialog
{
    Q_OBJECT
public:
    explicit Registrator(QDialog *parent = nullptr);
    ~Registrator() = default;
signals:

private slots:
    void on_RegpushButton_clicked();

private:
    Ui::Dialog* ui;
signals:
    void Registed(QString passport, QString name);
};

#endif // REGISTRATOR_H
