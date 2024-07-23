#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "DataBase.h"
#include "DrawData.h"
#include "createlinedialog.h"
#include "createrectangledialog.h"
#include "createcircledialog.h"
#include "createpolylinedialog.h"
#include "errordialog.h"
#include "QListWidget"
#include "QMouseEvent"
#include "QGraphicsSceneMouseEvent"
#include "drawclickscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnEnter_clicked();
    void on_btnDraw_clicked();

    void on_btnCreatePolyline_clicked();
    void on_btnCreateCircle_clicked();
    void on_btnCreateRectangle_clicked();
    void on_btnCreateLine_clicked();

    void on_btnCreateLineWithClik_clicked();
    void on_btnCreateCircleWithClick_clicked();
    void on_btnCreatePolylineWithClick_clicked();

private:
    void Draw(DrawData::ptr data);
    void appendInfoToListWindget(QString typeID, QString ObjectID, QString name);
    void addObjetToDb(object::ptr obj);
    void vectorisationAndDraw();
    void addObjectToDbAndVectorisation(int typeId);

    DataBase::ptr db;

    Ui::MainWindow *ui;
    DrawClickScene* objectScene;
};
#endif // MAINWINDOW_H
