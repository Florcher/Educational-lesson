#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include "DataBase.h"
#include <vector>
#include "DrawData.h"

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

private:
    void Draw(DrawData::ptr data);

    std::shared_ptr<DataBase> db;

    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    std::vector<QGraphicsLineItem> items;
};
#endif // MAINWINDOW_H
