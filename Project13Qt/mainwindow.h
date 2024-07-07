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

private:
    void Draw(DrawData::ptr data);
    void appendInfoToListWindget(QString typeID, QString ObjectID, QString name);
    void addObjetToDb(object::ptr obj);

    DataBase::ptr db;

    Ui::MainWindow *ui;
    QGraphicsScene* objectScene;
};
#endif // MAINWINDOW_H
