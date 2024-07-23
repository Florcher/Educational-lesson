#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Input.h"
#include "Vectoriser.h"
#include "QFont"
#include "QFileDialog"
#include "QMouseEvent"
#include "errordatadialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = std::make_shared<DataBase>();

    objectScene = new DrawClickScene();
    ui->graphicsView->setScene(objectScene);

    appendInfoToListWindget("TypeID", "ObjectID", "Name");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectScene;
}

void MainWindow::on_btnEnter_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("открыть файл"), QDir::currentPath(), tr("*.txt"));
    try{
        Input in;
        db = in.input(filename.toStdString());
        auto objects = db->getObjects();
        for(auto obj : objects){
            appendInfoToListWindget(QString::number(obj->getType()), QString::number(obj->getId()), QString::fromStdString(obj->getName()));
        }
    }
    catch(...){
        errorDialog dialog;
        dialog.exec();
    }
}

void MainWindow::on_btnDraw_clicked()
{
    vectorisationAndDraw();
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

    ui->listWidget->addItem(info);
}

void MainWindow::addObjetToDb(object::ptr obj)
{
    db->addObject(obj);
    appendInfoToListWindget(QString::number(obj->getType()), QString::number(obj->getId()), QString::fromStdString(obj->getName()));
}

void MainWindow::vectorisationAndDraw()
{
    Vectoriser vec;
    vec.draw(db);

    auto objects = db->getObjects();
    for(auto obj : objects){
        Draw(vec.getData(obj->getId()));
    }
}

void MainWindow::addObjectToDbAndVectorisation(int typeId)
{
    try{
        addObjetToDb(objectScene->getObject(typeId));
        vectorisationAndDraw();
    }
    catch(...){
        ErrorDataDialog dialog;
        dialog.exec();
    }
}

void MainWindow::on_btnCreateLine_clicked()
{
    CreateLineDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto line = std::make_shared<Line>("Line", dialog.getStartPoint(),dialog.getEndPoint());
        addObjetToDb(line);
    }
}

void MainWindow::on_btnCreateRectangle_clicked()
{
    CreateRectangleDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto rec = std::make_shared<Rectangle>("Rectangle", dialog.getLeftDownPoint(), dialog.getLenth(), dialog.getWidth());
        addObjetToDb(rec);
    }
}

void MainWindow::on_btnCreateCircle_clicked()
{
    CreateCircleDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto circle = std::make_shared<Circle>("Circle", dialog.getCenter(), dialog.getRadius());
        addObjetToDb(circle);
    }
}

void MainWindow::on_btnCreatePolyline_clicked()
{
    CreatePolylineDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto polyline = std::make_shared<Polyline>("Polyline", dialog.getPoints());
        addObjetToDb(polyline);
    }
}

void MainWindow::on_btnCreateLineWithClik_clicked()
{
    addObjectToDbAndVectorisation(Line::Type());
}


void MainWindow::on_btnCreateCircleWithClick_clicked()
{
    addObjectToDbAndVectorisation(Circle::Type());
}


void MainWindow::on_btnCreatePolylineWithClick_clicked()
{
    addObjectToDbAndVectorisation(Polyline::Type());
}

