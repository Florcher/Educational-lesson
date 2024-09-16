#include "errordialog.h"
#include "ui_errordialog.h"

errorDialog::errorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::errorDialog)
{
    ui->setupUi(this);
}

errorDialog::~errorDialog()
{
    delete ui;
}

void errorDialog::on_btnExit_clicked()
{
    errorDialog::accept();
}

