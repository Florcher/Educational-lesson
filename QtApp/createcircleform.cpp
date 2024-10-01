#include "createcircleform.h"
#include "ui_createcircleform.h"

CreateCircleForm::CreateCircleForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateCircleForm)
{
    ui->setupUi(this);
}

CreateCircleForm::~CreateCircleForm()
{
    delete ui;
}

void CreateCircleForm::on_btnEnterData_clicked()
{
    vector2D center{ui->editCenterX->text().toDouble(), ui->editCenterY->text().toDouble()};
    double radius = ui->editRadius->text().toDouble();

    Circle circle{"Circle", center, radius};
    object::ptr obj = std::make_shared<Circle>(circle);
    ui->editCenterX->clear();
    ui->editCenterY->clear();
    ui->editRadius->clear();
    emit signal(obj);
}


void CreateCircleForm::on_btnExit_clicked()
{
    ui->editCenterX->clear();
    ui->editCenterY->clear();
    ui->editRadius->clear();
    emit signalExit();
}

