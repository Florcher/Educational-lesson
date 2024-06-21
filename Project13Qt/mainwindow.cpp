#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Input.h"
#include "Vectoriser.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    db = std::make_shared<DataBase>();

    lineForm = new CreateLineForm();
    connect(lineForm, &CreateLineForm::signal,this,&MainWindow::Lineslot);
    connect(lineForm, &CreateLineForm::signalExit,this,&MainWindow::LineExitSlot);

    rectangleForm = new CreateRectangleForm();
    connect(rectangleForm, &CreateRectangleForm::signal,this,&MainWindow::Rectangleslot);
    connect(rectangleForm, &CreateRectangleForm::signalExit,this, &MainWindow::RectangleExitSlot);

    circleForm = new CreateCircleForm();
    connect(circleForm, &CreateCircleForm::signal,this,&MainWindow::Circleslot);
    connect(circleForm, &CreateCircleForm::signalExit,this,&MainWindow::CircleExitSlot);

    polylineForm = new CreatePolylineForm();
    connect(polylineForm, &CreatePolylineForm::signal,this,&MainWindow::Polylineslot);
    connect(polylineForm, &CreatePolylineForm::signalExit,this,&MainWindow::PolylineExitSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete lineForm;
    delete rectangleForm;
    delete circleForm;
    delete polylineForm;
}

void MainWindow::on_btnEnter_clicked()
{
    auto filename = ui->lineEdit->text();
    Input in;
    db = in.input(filename.toStdString());
}

void MainWindow::on_btnDraw_clicked()
{
    Vectoriser vec;
    vec.draw(db);

    auto objects = db->getObjects();
    for(auto obj : objects)
        Draw(vec.getData(obj->getId()));
}

void MainWindow::Draw(DrawData::ptr data)
{
    auto lines = data->getData();
    for(auto line : lines){

        qreal x1 = line.start.x;
        qreal y1 = line.start.y;

        qreal x2 = line.end.x;
        qreal y2 = line.end.y;

        scene->addLine(x1,y1,x2,y2, QPen(Qt::red));
    }
}

void MainWindow::Lineslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    lineForm->hide();

}

void MainWindow::Rectangleslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    rectangleForm->hide();
}

void MainWindow::Circleslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    circleForm->hide();
}

void MainWindow::Polylineslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    polylineForm->hide();
}

void MainWindow::LineExitSlot()
{
    lineForm->hide();
}

void MainWindow::RectangleExitSlot()
{
    rectangleForm->hide();
}

void MainWindow::CircleExitSlot()
{
    circleForm->hide();
}

void MainWindow::PolylineExitSlot()
{
    polylineForm->hide();
}

void MainWindow::on_btnCreateLine_clicked()
{
    lineForm->show();
}

void MainWindow::on_btnCreateRectangle_clicked()
{
    rectangleForm->show();
}

void MainWindow::on_btnCreateCircle_clicked()
{
    circleForm->show();
}

void MainWindow::on_btnCreatePolyline_clicked()
{
    polylineForm->show();
}









