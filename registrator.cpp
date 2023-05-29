#include "registrator.h"
#include "qvalidator.h"


Registrator::Registrator(QDialog *parent)
    : QDialog{parent},
      ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegularExpression rx_num("[0-9]{4}-[0-9]{6}");
    QRegularExpressionValidator *num_validator = new QRegularExpressionValidator(rx_num, this);
    ui->PassportlineEdit->setValidator(num_validator);
}

void Registrator::on_RegpushButton_clicked()
{
    if(ui->NamelineEdit->text() != "" && ui->PassportlineEdit->text() != ""){
        emit Registed(ui->PassportlineEdit->text(),ui->NamelineEdit->text());
        this->~Registrator();
    }

}

