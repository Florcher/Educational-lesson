#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Input.h"
#include "Vectoriser.h"
#include "QFont"
#include "QFileDialog"
#include "QMouseEvent"
#include "errordatadialog.h"
#include "QMessageBox"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = std::make_shared<DataBase>();

    dbview = new DataBaseView();
    ui->graphicsView->setScene(dbview);

    appendInfoToListWindget("TypeID", "ObjectID", "Name");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dbview;
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

        dbview->addLine(x1,y1,x2,y2, QPen(Qt::red));
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

void MainWindow::addObjectToDb(object::ptr obj)
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

void MainWindow::addObjectToDbAndVectorisation(std::shared_ptr<object> obj)
{
    addObjectToDb(obj);
    vectorisationAndDraw();
}

void MainWindow::on_btnCreateLine_clicked()
{
    CreateLineDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto line = std::make_shared<Line>("Line", dialog.getStartPoint(),dialog.getEndPoint());
        addObjectToDb(line);
    }
}

void MainWindow::on_btnCreateRectangle_clicked()
{
    CreateRectangleDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto rec = std::make_shared<Rectangle>("Rectangle", dialog.getLeftDownPoint(), dialog.getLenth(), dialog.getWidth());
        addObjectToDb(rec);
    }
}

void MainWindow::on_btnCreateCircle_clicked()
{
    CreateCircleDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto circle = std::make_shared<Circle>("Circle", dialog.getCenter(), dialog.getRadius());
        addObjectToDb(circle);
    }
}

void MainWindow::on_btnCreatePolyline_clicked()
{
    CreatePolylineDialog dialog;
    auto res = dialog.exec();
    if(res == QDialog::Accepted){
        auto polyline = std::make_shared<Polyline>("Polyline", dialog.getPoints());
        addObjectToDb(polyline);
    }
}

void MainWindow::on_btnCreateLineWithClik_clicked()
{
    try{
        auto start = dbview->getPoint();
        auto end = dbview->getPoint();
        auto line = std::make_shared<Line>("Line", start, end);
        addObjectToDbAndVectorisation(line);
    }
    catch(...){

    }
}

void MainWindow::on_btnCreateRectangleWithClick_clicked()
{
    try{
    auto ldp = dbview->getPoint();
    auto rdp = dbview->getPoint();
    auto ulp = dbview->getPoint();

    auto lenth = (rdp - ldp).length();
    auto width = (ulp - ldp).length();

    auto rec = std::make_shared<Rectangle>("REctangle",ldp,lenth, width);
    addObjectToDbAndVectorisation(rec);
    }
    catch(...){

    }
}

void MainWindow::on_btnCreateCircleWithClick_clicked()
{
    try{
        auto center = dbview->getPoint();
        auto oncurve = dbview->getPoint();
        auto radius = (oncurve - center).length();
        auto circle = std::make_shared<Circle>("Circle", center, radius);
        addObjectToDbAndVectorisation(circle);
    }
    catch(...){

    }
}


void MainWindow::on_btnCreatePolylineWithClick_clicked()
{
    std::vector<vector2D> pts;
    try{
        while(true)
            pts.push_back(dbview->getPoint());
    }
    catch(...){
        if(pts.size() > 1){
            auto pline = std::make_shared<Polyline>("Polyline", pts);
            addObjectToDbAndVectorisation(pline);
        } else{

        }
    }
}

void MainWindow::on_btnClearScene_clicked()
{
    dbview->clear();
}

void MainWindow::on_btnCreatePolygonWithClick_clicked()
{
    std::vector<vector2D> pts;
    try{
        while(true)
            pts.push_back(dbview->getPoint());
    }
    catch(...){
        if(pts.size() > 1){
            auto polygon = std::make_shared<Polygon>("Polyline", pts);
            addObjectToDbAndVectorisation(polygon);
        } else{

        }
    }
}

void MainWindow::on_btnStitching_clicked()
{
    std::vector<vector2D> pts;
    std::vector<Line::ptr> lines;

    std::vector<object::ptr> obj = db->getObjects();
    for(int i = 0; i < obj.size(); i++){
        if(obj[i]->getType() == 1)
            lines.push_back(std::dynamic_pointer_cast<Line>(obj[i]));
    }

    pts.push_back(lines[0]->getStart());
    pts.push_back(lines[0]->getEnd());
    for(int i = 0; i < lines.size() - 1; i++){   
        vector2D coordinate = lines[i + 1]->getEnd() - lines[i + 1]->getStart();
        vector2D point{lines[i]->getEnd().x + coordinate.x,lines[i]->getEnd().y +coordinate.y};
        pts.push_back(point);
    }

    auto pline = std::make_shared<Polyline>("Polyline", pts);
    addObjectToDb(pline);

    for(int i =0; i < lines.size(); i++){
        db->removeObject(lines[i]->getId());
    }
}

