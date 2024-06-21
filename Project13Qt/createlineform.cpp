#include "createlineform.h"
#include "ui_createlineform.h"
#include "Objects.h"

CreateLineForm::CreateLineForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreateLineForm)
{
    ui->setupUi(this);
}

CreateLineForm::~CreateLineForm()
{
    delete ui;
}

void CreateLineForm::on_btnEnterData_clicked()
{
    vector2D start{ui->editStartX->text().toDouble(), ui->editStartY->text().toDouble()};
    vector2D end{ui->editEndX->text().toDouble(), ui->editEndY->text().toDouble()};
    Line line("line", 4, start, end);
    object::ptr obj = std::make_shared<Line>(line);
    ui->editStartX->clear();
    ui->editStartY->clear();
    ui->editEndX->clear();
    ui->editEndY->clear();
    emit signal(obj);
}


void CreateLineForm::on_btnExit_clicked()
{
    ui->editStartX->clear();
    ui->editStartY->clear();
    ui->editEndX->clear();
    ui->editEndY->clear();
    emit signalExit();
}

