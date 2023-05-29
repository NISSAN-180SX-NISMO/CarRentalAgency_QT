#include "appstate.h"


AppState::AppState(QWidget *parent)
    : QWidget{parent}
{

}

bool AppState::inAccountNow = false;

void AppState::inAccount(Ui::Widget* ui, Client* current){

    qDebug() << 3;
    inAccountNow = true;
    ui->ExitClientButton->setEnabled(true);
    ui->groupBox->setEnabled(true);
    ui->groupBox_2->setEnabled(true);

    ui->RegistClientButton->setEnabled(false);
    ui->EntryClientButton->setEnabled(false);

    emit ui->Class_comboBox->activated(0);
    if (ui->Brand_comboBox->currentText() == "")
        ui->Brand_comboBox->setEnabled(false);
    else emit ui->Brand_comboBox->activated(0);

    emit ui->Period_comboBox->activated(0);
    if (ui->Number_comboBox->currentText() == "")
        ui->Number_comboBox->setEnabled(false);
    else emit ui->Number_comboBox->activated(0);

    ui->Issue_pushButton->setEnabled(false);
    ui->lineEdit->setText(current->getPassport());
    ui->lineEdit_2->setText(current->getName());
    ui->Payment_checkBox->setEnabled(true);
    ui->Payment_checkBox->setCheckState(Qt::CheckState::Unchecked);

    ui->ReturnpushButton->setEnabled(false);
    auto CarsInAreas = current->inRent.getAll();
    ui->ReturnNumbercomboBox->clear();
    for (auto &car : CarsInAreas)
        ui->ReturnNumbercomboBox->addItem(car.first->getNumber());
    if (CarsInAreas.size())
        emit ui->ReturnNumbercomboBox->activated(0);

    ui->checkBox_2->setEnabled(true);
    ui->checkBox_2->setCheckState(Qt::CheckState::Unchecked);
}


void AppState::choiceClient(Ui::Widget* ui, Client* current){
    ui->RegistClientButton->setEnabled(true);
    ui->EntryClientButton->setEnabled(true);
    inAccountNow = false;
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    current = new Client();
    ui->ExitClientButton->setEnabled(false);
    ui->groupBox->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
}
