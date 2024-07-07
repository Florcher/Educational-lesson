#include "createpolylinedialog.h"
#include "ui_createpolylinedialog.h"

createPolylineDialog::createPolylineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createPolylineDialog)
{
    ui->setupUi(this);
}

createPolylineDialog::~createPolylineDialog()
{
    delete ui;
}

void createPolylineDialog::on_btnEnterData_clicked()
{
    object::ptr obj = std::make_shared<Polyline>("Polyline", 0, points);
    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
    createPolylineDialog::accept();
    emit sendPolylineSignal(obj, QDialog::Accepted);
}


void createPolylineDialog::on_btnExit_clicked()
{
    points.clear();
    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
    createPolylineDialog::reject();
}


void createPolylineDialog::on_btnNextPoint_clicked()
{
    points.push_back({ui->editCoordinateX->text().toDouble(),ui->editCoordinateY->text().toDouble()});

    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
}

