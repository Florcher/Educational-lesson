#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Vectoriser.h"
#include "QFont"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = std::make_shared<DataBase>();

    objectScene = new QGraphicsScene;
    ui->graphicsView->setScene(objectScene);

    lwidget = new QListWidget();
    lwidget->show();
    appendInfoToListWindget("TypeID", "ObjectID", "Name");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectScene;
}

void MainWindow::on_btnEnter_clicked()
{
    EnterFileDialog dialog;
    connect(&dialog, &EnterFileDialog::enterDatasignal, this, &MainWindow::getDataBaseFromDialog);
    dialog.exec();
    auto objects = db->getObjects();
    for(auto obj : objects){
        appendInfoToListWindget(QString::number(obj->getType()), QString::number(obj->getId()), QString::fromStdString(obj->getName()));
    }
}

void MainWindow::on_btnDraw_clicked()
{
    Vectoriser vec;
    vec.draw(db);

    auto objects = db->getObjects();
    for(auto obj : objects){
        Draw(vec.getData(obj->getId()));
    }
}

void MainWindow::Draw(DrawData::ptr data)
{
    auto lines = data->getData();
    for(auto line : lines){

        qreal x1 = line.start.x;
        qreal y1 = line.start.y;

        qreal x2 = line.end.x;
        qreal y2 = line.end.y;

        objectScene->addLine(x1,y1,x2,y2, QPen(Qt::red));
    }
}

void MainWindow::appendInfoToListWindget(QString typeID, QString ObjectID, QString name)
{
    QString info;

    info.append(typeID);
    info.append(" ");
    info.append(ObjectID);
    info.append(" ");
    info.append(name);
    info.append("\n");

    lwidget->addItem(info);
}

void MainWindow::addObjetToDb(object::ptr obj, int mark)
{
    if(mark == QDialog::Accepted){

    if(db->getObjectsCount() == 0)
        obj->setId(1);

    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);

    appendInfoToListWindget(QString::number(obj->getType()), QString::number(obj->getId()), QString::fromStdString(obj->getName()));
    }
}

void MainWindow::on_btnCreateLine_clicked()
{
    createlineDialog dialog(this);
    connect(&dialog, &createlineDialog::sendLineSignal, this, &MainWindow::addObjetToDb);
    dialog.exec();
}

void MainWindow::getDataBaseFromDialog(DataBase::ptr data)
{
    db = data;
}

void MainWindow::on_btnCreateRectangle_clicked()
{
    createRectangleDialog dialog;
    connect(&dialog, &createRectangleDialog::sendRectangleSignal, this, &MainWindow::addObjetToDb);
    dialog.exec();
}

void MainWindow::on_btnCreateCircle_clicked()
{
    createCircleDialog dialog;
    connect(&dialog, &createCircleDialog::sendCircleSignal, this, &MainWindow::addObjetToDb);
    dialog.exec();
}

void MainWindow::on_btnCreatePolyline_clicked()
{
    createPolylineDialog dialog;
    connect(&dialog, &createPolylineDialog::sendPolylineSignal, this, &MainWindow::addObjetToDb);
    dialog.exec();
}












