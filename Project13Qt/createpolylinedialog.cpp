#include "createpolylinedialog.h"
#include "ui_createpolylinedialog.h"

CreatePolylineDialog::CreatePolylineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreatePolylineDialog)
{
    ui->setupUi(this);
}

CreatePolylineDialog::~CreatePolylineDialog()
{
    delete ui;
}

std::vector<vector2D> CreatePolylineDialog::getPoints() const
{
    return points;
}

void CreatePolylineDialog::on_btnNextPoint_clicked()
{
    points.push_back({ui->editCoordinateX->text().toDouble(), ui->editCoordinateY->text().toDouble()});
    ui->editCoordinateX->clear();
    ui->editCoordinateY->clear();
}

