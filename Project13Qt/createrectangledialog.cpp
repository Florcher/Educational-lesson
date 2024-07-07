#include "createrectangledialog.h"
#include "ui_createrectangledialog.h"

createRectangleDialog::createRectangleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createRectangleDialog)
{
    ui->setupUi(this);
}

createRectangleDialog::~createRectangleDialog()
{
    delete ui;
}

void createRectangleDialog::on_btnEnterData_clicked()
{
    vector2D ldp{ui->editLdpX->text().toDouble(),ui->editLdpY->text().toDouble()};
    double lenth = ui->editLenth->text().toDouble();
    double width = ui->editWidth->text().toDouble();

    object::ptr obj = std::make_shared<Rectangle>("Rectangle", 0, ldp, lenth, width);
    ui->editLdpX->clear();
    ui->editLdpY->clear();
    ui->editLenth->clear();
    ui->editWidth->clear();
    createRectangleDialog::accept();
    emit sendRectangleSignal(obj, QDialog::Accepted);
}


void createRectangleDialog::on_btnExit_clicked()
{
    ui->editLdpX->clear();
    ui->editLdpY->clear();
    ui->editLenth->clear();
    ui->editWidth->clear();
    createRectangleDialog::reject();
}

