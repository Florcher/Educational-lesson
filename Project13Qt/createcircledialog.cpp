#include "createcircledialog.h"
#include "ui_createcircledialog.h"

createCircleDialog::createCircleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createCircleDialog)
{
    ui->setupUi(this);
}

createCircleDialog::~createCircleDialog()
{
    delete ui;
}

void createCircleDialog::on_btnEnterData_clicked()
{
    vector2D center{ui->editCenterX->text().toDouble(), ui->editCenterY->text().toDouble()};
    double radius = ui->editRadius->text().toDouble();

    object::ptr obj = std::make_shared<Circle>("Circle", 0, center, radius);
    ui->editCenterX->clear();
    ui->editCenterY->clear();
    ui->editRadius->clear();
    createCircleDialog::accept();
    emit sendCircleSignal(obj, QDialog::Accepted);
}


void createCircleDialog::on_btnExit_clicked()
{
    ui->editCenterX->clear();
    ui->editCenterY->clear();
    ui->editRadius->clear();
    createCircleDialog::reject();
}

