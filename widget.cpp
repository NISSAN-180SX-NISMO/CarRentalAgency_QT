#include "widget.h"
#include "ui_widget.h"

#include <qDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , info(this)
{
    ui->setupUi(this);
    currentClient = new Client();
    connect(this, SIGNAL(ClasChanged(Class)), &info, SLOT(changeClas(Class)));
    connect(this, SIGNAL(BrandChanged(QString)), &info, SLOT(changeBrand(QString)));
    connect(this, SIGNAL(PeriodChanged(Period)), &info, SLOT(changePeriod(Period)));
    connect(this, SIGNAL(NumberChanged(QString)), &info, SLOT(changeNumber(QString)));
    connect(this, SIGNAL(SeverityChanged(Severity)), &info, SLOT(changeSeverity(Severity)));

    connect(this, SIGNAL(ClasChanged(Class)), this, SLOT(getRentCost()));
    connect(this, SIGNAL(BrandChanged(QString)), this, SLOT(getRentCost()));
    connect(this, SIGNAL(PeriodChanged(Period)), this, SLOT(getRentCost()));
    connect(this, SIGNAL(NumberChanged(QString)), this, SLOT(getRentCost()));

    connect(this, SIGNAL(SeverityChanged(Severity)), this, SLOT(getRepairCost()));
    connect(ui->ReturnNumbercomboBox, SIGNAL(activated(int)), this, SLOT(getRepairCost()));

    connect(this, SIGNAL(ClasChanged(Class)), this, SLOT(getBrands(Class)));
    connect(this, SIGNAL(BrandChanged(QString)), this, SLOT(getNumbers(QString)));

    _init();

    update();
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    AppState::choiceClient(ui,currentClient);

}

void Widget::_init(){
    clients.registClient(new Client("1234-234567", "Петров Иван Васильевич"));
    clients.registClient(new Client("2345-345678", "Васильев Петр Иванович"));
    clients.registClient(new Client("3456-456789", "Иванов Василий Петрович"));

    CarBuilder car;
    DB.insert(Class::Business, car.CreateBusiness().setBrand("Mercedess-Benz").setNumber("A666TC").getCar());
    DB.insert(Class::Business, car.CreateBusiness().setBrand("Audi A6").setNumber("H777OT").getCar());
    DB.insert(Class::Business, car.CreateBusiness().setBrand("Lexus GS").setNumber("K999MB").getCar());
    DB.insert(Class::Business, car.CreateBusiness().setBrand("BMW 530 E").setNumber("A000AT").getCar());

    DB.insert(Class::Sport, car.CreateSport().setBrand("Toyota Supra").setNumber("K549AP").getCar());
    DB.insert(Class::Sport, car.CreateSport().setBrand("Nissan 180SX").setNumber("O787MH").getCar());
    DB.insert(Class::Sport, car.CreateSport().setBrand("Acura NSX").setNumber("A485XB").getCar());
    DB.insert(Class::Sport, car.CreateSport().setBrand("Toyota Mark II").setNumber("E681AE").getCar());
    DB.insert(Class::Sport, car.CreateSport().setBrand("Mazda RX7").setNumber("P295BC").getCar());
    DB.insert(Class::Sport, car.CreateSport().setBrand("Nissan Skyline GTR").setNumber("A348KM").getCar());

    DB.insert(Class::OffRoad, car.CreateOffRoad().setBrand("Range Rover IV").setNumber("A985AP").getCar());
    DB.insert(Class::OffRoad, car.CreateOffRoad().setBrand("Jeep Renegad").setNumber("E359KA").getCar());
    DB.insert(Class::OffRoad, car.CreateOffRoad().setBrand("Mitsubishi Pajero IV").setNumber("A340MB").getCar());
    DB.insert(Class::OffRoad, car.CreateOffRoad().setBrand("Land Rover Defender").setNumber("C239KC").getCar());
    DB.insert(Class::OffRoad, car.CreateOffRoad().setBrand("Touota Fortuner II").setNumber("K904ET").getCar());

    DB.insert(Class::Electic, car.CreateElectric().setBrand("Tesla Model X").setNumber("K736MC").getCar());
    DB.insert(Class::Electic, car.CreateElectric().setBrand("Nissan Leaf").setNumber("E242MP").getCar());
    DB.insert(Class::Electic, car.CreateElectric().setBrand("BMW iX").setNumber("B004KO").getCar());
}

void Widget::showAllCars(){
    qDebug() << 5;
    while (ui->AllCarstableWidget->rowCount())
        ui->AllCarstableWidget->removeRow(0);

    ui->AllCarstableWidget->setColumnCount(3);
    ui->AllCarstableWidget->setHorizontalHeaderLabels(QStringList() << "Класс авто" << "Марка авто" << "Гос. номер");
    int row = 0;
    for (auto & car : DB.getAll(Class::Business)){
        ui->AllCarstableWidget->insertRow(row);
        ui->AllCarstableWidget->setItem(row, 0, new QTableWidgetItem("Business"));
        ui->AllCarstableWidget->setItem(row, 1, new QTableWidgetItem(car->getBrand()));
        ui->AllCarstableWidget->setItem(row, 2, new QTableWidgetItem(car->getNumber()));

        row++;
    }
    for (auto & car : DB.getAll(Class::Sport)){
        ui->AllCarstableWidget->insertRow(row);
        ui->AllCarstableWidget->setItem(row, 0, new QTableWidgetItem("Sport"));
        ui->AllCarstableWidget->setItem(row, 1, new QTableWidgetItem(car->getBrand()));
        ui->AllCarstableWidget->setItem(row, 2, new QTableWidgetItem(car->getNumber()));
        row++;
    }
    for (auto & car : DB.getAll(Class::OffRoad)){
        ui->AllCarstableWidget->insertRow(row);
        ui->AllCarstableWidget->setItem(row, 0, new QTableWidgetItem("OffRoad"));
        ui->AllCarstableWidget->setItem(row, 1, new QTableWidgetItem(car->getBrand()));
        ui->AllCarstableWidget->setItem(row, 2, new QTableWidgetItem(car->getNumber()));
        row++;
    }
    for (auto & car : DB.getAll(Class::Electic)){
        ui->AllCarstableWidget->insertRow(row);
        ui->AllCarstableWidget->setItem(row, 0, new QTableWidgetItem("Electic"));
        ui->AllCarstableWidget->setItem(row, 1, new QTableWidgetItem(car->getBrand()));
        ui->AllCarstableWidget->setItem(row, 2, new QTableWidgetItem(car->getNumber()));
        row++;
    }
    ui->AllCarstableWidget->setColumnWidth(1, 200);
    qDebug() << 6;
}

void Widget::getBrands(Class clas){
    ui->Brand_comboBox->setEnabled(true);
    auto brands = DB.find(clas);
    ui->Brand_comboBox->clear();
    for (auto &brand : brands)
        ui->Brand_comboBox->addItem(brand->getBrand());
}

void Widget::getNumbers(QString brand){
    QVector<Car*> numbers;
    switch (ui->Class_comboBox->currentIndex()){
    case 0: numbers = DB.find(Class::Business, brand); break;
    case 1: numbers = DB.find(Class::Sport, brand); break;
    case 2: numbers = DB.find(Class::OffRoad, brand); break;
    case 3: numbers = DB.find(Class::Electic, brand); break;
    }
    ui->Number_comboBox->clear();
    for (auto &number : numbers)
        ui->Number_comboBox->addItem(number->getNumber());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Payment_checkBox_stateChanged(int arg1)
{
    if(!arg1) {
        ui->Issue_pushButton->setEnabled(false);
        ui->Class_comboBox->setEnabled(true);
        ui->Brand_comboBox->setEnabled(true);
        ui->Period_comboBox->setEnabled(true);
        ui->Number_comboBox->setEnabled(true);
        ui->Payment_checkBox->setEnabled(true);
    }
    else {
        ui->Issue_pushButton->setEnabled(true);
        ui->Class_comboBox->setEnabled(false);
        ui->Brand_comboBox->setEnabled(false);
        ui->Period_comboBox->setEnabled(false);
        ui->Number_comboBox->setEnabled(false);
        ui->Payment_checkBox->setEnabled(false);
    }
}

void Widget::on_RegistClientButton_clicked(){
    qDebug() << 1;
    reg = new Registrator;
    connect(reg, SIGNAL(Registed(QString,QString)), this, SLOT(registed(QString,QString)));
    reg->show();
}

void Widget::registed(QString passport, QString name){
    qDebug() << 2;
    if (clients.find(passport)) {
        qDebug() << "DUPLICATE!!!";
        return;
    }
    this->clients.registClient(new Client(passport, name));
    this->currentClient = this->clients.find(passport);
    update();
    AppState::inAccount(ui, currentClient);
}

void Widget::on_EntryClientButton_clicked(){
    login = new LogIner;
    connect(login, SIGNAL(LogIn(QString)), this, SLOT(logined(QString)));
    login->show();
}

void Widget::logined(QString passport){
    Client* client = clients.find(passport);
    if (!client) {
        qDebug() << "НЕТ ТАКОГО!!!";
        return;
    } else {
        currentClient = client;
        AppState::inAccount(ui, currentClient);
        update();
    }
}

void Widget::on_ExitClientButton_clicked(){
    AppState::choiceClient(ui, currentClient);
    update();
}

void Widget::showAllClients(){
    while (ui->ClientHistorytableWidget->rowCount())
        ui->ClientHistorytableWidget->removeRow(0);
    ui->ClientgroupBox->setTitle("Все зарегистрированные клиенты");
    ui->ClientHistorytableWidget->setColumnCount(2);
    ui->ClientHistorytableWidget->setHorizontalHeaderLabels(QStringList() << "Номер паспорта" << "ФИО");
    int row = 0;
    for (auto & client : this->clients.allClients){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem(client->getPassport()));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(client->getName()));

        row++;
    }
    ui->ClientHistorytableWidget->setColumnWidth(0, 150);
    ui->ClientHistorytableWidget->setColumnWidth(1, 274);
}

void Widget::showCurrentClient(){
    qDebug() << 7;
    while (ui->ClientHistorytableWidget->rowCount())
        ui->ClientHistorytableWidget->removeRow(0);
    ui->ClientgroupBox->setTitle("История клиента");
    ui->ClientHistorytableWidget->setColumnCount(4);
    ui->ClientHistorytableWidget->setHorizontalHeaderLabels(QStringList() << "Класс авто" << "Марка авто" << "Гос. номер" << "Период");
    int row = 0;
    for (auto & car : currentClient->history.getAll(Class::Business)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Business"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));

        row++;
    }
    for (auto & car : currentClient->history.getAll(Class::Sport)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Sport"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        row++;
    }
    for (auto & car : currentClient->history.getAll(Class::OffRoad)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("OffRoad"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        row++;
    }
    for (auto & car : currentClient->history.getAll(Class::Electic)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Electic"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        row++;
    }
    for (auto & car : currentClient->inRent.getAll(Class::Business)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Business"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        ui->ClientHistorytableWidget->item(row,0)->setBackground(Qt::red);
        row++;
    }
    for (auto & car : currentClient->inRent.getAll(Class::Sport)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Sport"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        ui->ClientHistorytableWidget->item(row,0)->setBackground(Qt::red);
        row++;
    }
    for (auto & car : currentClient->inRent.getAll(Class::OffRoad)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("OffRoad"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        ui->ClientHistorytableWidget->item(row,0)->setBackground(Qt::red);
        row++;
    }
    for (auto & car : currentClient->inRent.getAll(Class::Electic)){
        ui->ClientHistorytableWidget->insertRow(row);
        ui->ClientHistorytableWidget->setItem(row, 0, new QTableWidgetItem("Electic"));
        ui->ClientHistorytableWidget->setItem(row, 1, new QTableWidgetItem(car.first->getBrand()));
        ui->ClientHistorytableWidget->setItem(row, 2, new QTableWidgetItem(car.first->getNumber()));
        ui->ClientHistorytableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(int(car.second)) + " дня(ей)"));
        ui->ClientHistorytableWidget->item(row,0)->setBackground(Qt::red);
        row++;
    }
    ui->ClientHistorytableWidget->setColumnWidth(0, 70);
    ui->ClientHistorytableWidget->setColumnWidth(1, 154);
    ui->ClientHistorytableWidget->setColumnWidth(2, 100);
    ui->ClientHistorytableWidget->setColumnWidth(3, 100);
}

void Widget::on_Class_comboBox_activated(int index)
{
    switch (index){
    case 0: emit this->ClasChanged(Class::Business); break;
    case 1: emit this->ClasChanged(Class::Sport); break;
    case 2: emit this->ClasChanged(Class::OffRoad); break;
    case 3: emit this->ClasChanged(Class::Electic); break;
    }
    ui->Number_comboBox->clear();
    emit BrandChanged(ui->Brand_comboBox->currentText());
}

void Widget::on_Brand_comboBox_activated(int index)
{
    ui->Number_comboBox->clear();
    emit BrandChanged(ui->Brand_comboBox->currentText());
}

void Widget::on_Period_comboBox_activated(int index){
    switch (index){
    case 0: emit this->PeriodChanged(Period::OneDay); break;
    case 1: emit this->PeriodChanged(Period::TwoDay); break;
    case 2: emit this->PeriodChanged(Period::ThreeDay); break;
    case 3: emit this->PeriodChanged(Period::OneWeek); break;
    case 4: emit this->PeriodChanged(Period::TwoWeek); break;
    }
}

void Widget::on_Number_comboBox_activated(int index){
    emit NumberChanged(ui->Number_comboBox->currentText());
}

void Widget::getRentCost(){
    ui->RentCostLabel->setText(QString::number(info.getCar()->getRentCost(info.getPeriod())) + " руб.");
}

void Widget::on_Issue_pushButton_clicked(){
    Car* NewCar = info.getCar();
    if (NewCar->getBrand().isEmpty() || NewCar->getNumber().isEmpty()) {
        ui->Payment_checkBox->setEnabled(true);
        return;
    }
    else{
        currentClient->inRent.insert(NewCar->getClass(), NewCar, info.getPeriod());
        this->DB.remove(NewCar->getNumber());
        update();
        AppState::inAccount(ui, currentClient);
    }
}

void Widget::on_checkBox_2_stateChanged(int arg1){
    if (!ui->radioButton->isChecked() &&
            !ui->radioButton_2->isChecked() &&
            !ui->radioButton_3->isChecked() &&
            !ui->radioButton_4->isChecked())
        ui->checkBox_2->setCheckState(Qt::Unchecked);
    else {
        if(!arg1) {
            ui->ReturnpushButton->setEnabled(false);
            ui->radioButton->setEnabled(true);
            ui->radioButton_2->setEnabled(true);
            ui->radioButton_3->setEnabled(true);
            ui->radioButton_4->setEnabled(true);
            ui->ReturnNumbercomboBox->setEnabled(true);
             ui->checkBox_2->setEnabled(true);
        }
        else {
            ui->ReturnpushButton->setEnabled(true);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
            ui->radioButton_3->setEnabled(false);
            ui->radioButton_4->setEnabled(false);
            ui->ReturnNumbercomboBox->setEnabled(false);
            ui->checkBox_2->setEnabled(false);
        }
    }
}

void Widget::getRepairCost(){
    qDebug() << "getRepairCost";
    auto pair = currentClient->inRent.find(ui->ReturnNumbercomboBox->currentText());
    ui->RentCostLabel_2->setText(QString::number(pair.first->getRepairCost(info.getSeverity())) + " руб.");
}

void Widget::on_radioButton_clicked(){
    emit SeverityChanged(Severity::None);
}

void Widget::on_radioButton_2_clicked(){
    emit SeverityChanged(Severity::Small);
}

void Widget::on_radioButton_3_clicked(){
     emit SeverityChanged(Severity::Middle);
}

void Widget::on_radioButton_4_clicked(){
     emit SeverityChanged(Severity::High);
}

void Widget::on_ReturnpushButton_clicked(){
    auto pair = currentClient->inRent.find(ui->ReturnNumbercomboBox->currentText());
    currentClient->history.insert(pair.first->getClass(), pair.first, pair.second);
    DB.insert(pair.first->getClass(), pair.first);
    currentClient->inRent.remove(pair.first->getNumber());
    update(); AppState::inAccount(ui, currentClient);
}

void Widget::update(){
    qDebug() << "update";
    showAllCars();
    if(!AppState::inAccountNow) showAllClients();
    else showCurrentClient();
}
