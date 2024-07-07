#include "createlinedialog.h"
#include "ui_createlinedialog.h"

CreateLineDialog::CreateLineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateLineDialog)
{
    ui->setupUi(this);
}

CreateLineDialog::~CreateLineDialog()
{
    delete ui;
}

vector2D CreateLineDialog::getStartPoint() const
{
    return {ui->editStartX->text().toDouble(), ui->editStartY->text().toDouble()};
}

vector2D CreateLineDialog::getEndPoint() const
{
    return {ui->editEndX->text().toDouble(), ui->editEndY->text().toDouble()};
}
