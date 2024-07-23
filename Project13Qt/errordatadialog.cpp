#include "errordatadialog.h"
#include "ui_errordatadialog.h"

ErrorDataDialog::ErrorDataDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ErrorDataDialog)
{
    ui->setupUi(this);
}

ErrorDataDialog::~ErrorDataDialog()
{
    delete ui;
}

void ErrorDataDialog::on_btnExit_clicked()
{
    ErrorDataDialog::accept();
}

