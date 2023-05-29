#include "loginer.h"
#include "qregularexpression.h"
#include "qvalidator.h"

LogIner::LogIner(QDialog *parent)
    : QDialog{parent},
      ui(new Ui::Dialog_LogIn)
{
    ui->setupUi(this);
    QRegularExpression rx_num("[0-9]{4}-[0-9]{6}");
    QRegularExpressionValidator *num_validator = new QRegularExpressionValidator(rx_num, this);
    ui->PassportlineEdit->setValidator(num_validator);
}

void LogIner::on_EntrypushButton_clicked()
{
    if(ui->PassportlineEdit->text() != ""){
        emit LogIn(ui->PassportlineEdit->text());
        this->~LogIner();
    }

}
