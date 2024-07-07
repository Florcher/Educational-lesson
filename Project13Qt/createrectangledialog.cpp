#include "createrectangledialog.h"
#include "ui_createrectangledialog.h"

CreateRectangleDialog::CreateRectangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateRectangleDialog)
{
    ui->setupUi(this);
}

CreateRectangleDialog::~CreateRectangleDialog()
{
    delete ui;
}

vector2D CreateRectangleDialog::getLeftDownPoint() const
{
    return {ui->editLdpX->text().toDouble(), ui->editLdpY->text().toDouble()};
}

double CreateRectangleDialog::getLenth() const
{
    return ui->editLenth->text().toDouble();
}

double CreateRectangleDialog::getWidth() const
{
    return ui->editWidth->text().toDouble();
}
