#include "enterfiledialog.h"
#include "ui_enterfiledialog.h"
#include "Input.h"
#include "errordialog.h"
EnterFileDialog::EnterFileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EnterFileDialog)
{
    ui->setupUi(this);
}

EnterFileDialog::~EnterFileDialog()
{
    delete ui;
}

void EnterFileDialog::on_btnEnterData_clicked()
{
    try{
        auto filename = ui->editFileName->text();
        Input in;
        auto db = in.input(filename.toStdString());
        emit enterDatasignal(db);
        EnterFileDialog::accept();
    }
    catch(...){
        errorDialog dialog;
        dialog.exec();
    }
}

