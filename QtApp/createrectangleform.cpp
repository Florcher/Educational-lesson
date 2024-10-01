#include "createrectangleform.h"
#include "ui_createrectangleform.h"
#include "Objects.h"

CreateRectangleForm::CreateRectangleForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateRectangleForm)
{
    ui->setupUi(this);
}

CreateRectangleForm::~CreateRectangleForm()
{
    delete ui;
}

void CreateRectangleForm::on_btnEnterData_clicked()
{
    vector2D ldp{ui->editLdpX->text().toDouble(),ui->editLdpY->text().toDouble()};
    double lenth = ui->editLenth->text().toDouble();
    double width = ui->editWidth->text().toDouble();

    Rectangle rec{"Rectangle", ldp, lenth, width};
    object::ptr obj = std::make_shared<Rectangle>(rec);
    ui->editLdpX->clear();
    ui->editLdpY->clear();
    ui->editLenth->clear();
    ui->editWidth->clear();
    emit signal(obj);
}


void CreateRectangleForm::on_btnExit_clicked()
{
    ui->editLdpX->clear();
    ui->editLdpY->clear();
    ui->editLenth->clear();
    ui->editWidth->clear();
    emit signalExit();
}

