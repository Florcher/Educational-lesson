#include "createcircledialog.h"
#include "ui_createcircledialog.h"

CreateCircleDialog::CreateCircleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateCircleDialog)
{
    ui->setupUi(this);
}

CreateCircleDialog::~CreateCircleDialog()
{
    delete ui;
}

vector2D CreateCircleDialog::getCenter() const
{
    return {ui->editCenterX->text().toDouble(), ui->editCenterY->text().toDouble()};
}

double CreateCircleDialog::getRadius() const
{
    return ui->editRadius->text().toDouble();
}
