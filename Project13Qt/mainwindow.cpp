#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Input.h"
#include "Vectoriser.h"
#include "QFont"
#include "QFileDialog"
#include "QMouseEvent"
#include "errordatadialog.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = std::make_shared<DataBase>();

    dbview = new DataBaseView();
    ui->graphicsView->setScene(dbview);

    appendInfoToListWindget("TypeID", "ObjectID", "Name");
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
    delete dbview;
    delete lineForm;
    delete rectangleForm;
    delete circleForm;
    delete polylineForm;
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
<<<<<<< .mine
    vectorisationAndDraw();





=======
    Vectoriser vec;
    vec.draw(db);

    auto objects = db->getObjects();
    for(auto obj : objects)
        Draw(vec.getData(obj->getId()));
>>>>>>> .theirs
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

<<<<<<< .mine
void MainWindow::appendInfoToListWindget(QString typeID, QString ObjectID, QString name)
{
    QString info;

=======
void MainWindow::Lineslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);
>>>>>>> .theirs

<<<<<<< .mine
    info.append(typeID);
    info.append(" ");
    info.append(ObjectID);
    info.append(" ");
    info.append(name);
    info.append("\n");
=======
    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    lineForm->hide();



>>>>>>> .theirs

<<<<<<< .mine
    ui->listWidget->addItem(info);
}
=======
}

>>>>>>> .theirs

<<<<<<< .mine
void MainWindow::addObjectToDb(object::ptr obj)
{
    db->addObject(obj);
    appendInfoToListWindget(QString::number(obj->getType()), QString::number(obj->getId()), QString::fromStdString(obj->getName()));
}
=======
void MainWindow::Rectangleslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

>>>>>>> .theirs

<<<<<<< .mine
void MainWindow::vectorisationAndDraw()
{
    Vectoriser vec;
    vec.draw(db);
=======
    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    rectangleForm->hide();
}
>>>>>>> .theirs

<<<<<<< .mine
    auto objects = db->getObjects();
    for(auto obj : objects){
        Draw(vec.getData(obj->getId()));
    }
}
=======
void MainWindow::Circleslot(object::ptr obj)
{
    if(db->getObjectsCount() == 0)
        obj->setId(1);

>>>>>>> .theirs

<<<<<<< .mine
void MainWindow::addObjectToDbAndVectorisation(std::shared_ptr<object> obj)
{
    addObjectToDb(obj);
    vectorisationAndDraw();
}
=======
    obj->setId(db->getObjectsCount()+1);
    db->addObject(obj);
    circleForm->hide();
}

>>>>>>> .theirs

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

