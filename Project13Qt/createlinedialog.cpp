#include "createlinedialog.h"
#include "ui_createlinedialog.h"

createlineDialog::createlineDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createlineDialog)
{
    ui->setupUi(this);
}

createlineDialog::~createlineDialog()
{
    delete ui;
}

void createlineDialog::on_btnEnterData_clicked()
{
    vector2D start{ui->editStartX->text().toDouble(), ui->editStartY->text().toDouble()};
    vector2D end{ui->editEndX->text().toDouble(), ui->editEndY->text().toDouble()};

    object::ptr obj = std::make_shared<Line>("line", 0, start, end);
    ui->editStartX->clear();
    ui->editStartY->clear();
    ui->editEndX->clear();
    ui->editEndY->clear();
    createlineDialog::accept();
    emit sendLineSignal(obj, QDialog::Accepted);
}

void createlineDialog::on_btnExit_clicked()
{
    ui->editStartX->clear();
    ui->editStartY->clear();
    ui->editEndX->clear();
    ui->editEndY->clear();
    createlineDialog::reject();
}

