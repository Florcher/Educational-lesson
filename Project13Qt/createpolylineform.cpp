#include "createpolylineform.h"
#include "ui_createpolylineform.h"


CreatePolylineForm::CreatePolylineForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreatePolylineForm)
{
    ui->setupUi(this);
}

CreatePolylineForm::~CreatePolylineForm()
{
    delete ui;
}

void CreatePolylineForm::on_btnEnterData_clicked()
{
    Polyline polyline{"Polyline", 0, points};
    object::ptr obj = std::make_shared<Polyline>(polyline);
    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
    emit signal(obj);
}


void CreatePolylineForm::on_btnNextPoint_clicked()
{
    vector2D point{ui->editCoordinateX->text().toDouble(), ui->editCoordinateY->text().toDouble()};
    points.push_back(point);

    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
}


void CreatePolylineForm::on_btnExit_clicked()
{
    points.clear();
    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
    emit signalExit();
}

