#ifndef CREATEPOLYLINEFORM_H
#define CREATEPOLYLINEFORM_H

#include <QWidget>
#include "Objects.h"
#include <vector>

namespace Ui {
class CreatePolylineForm;
}

class CreatePolylineForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePolylineForm(QWidget *parent = nullptr);
    ~CreatePolylineForm();

signals:
    void signal(object::ptr obj);
    void signalExit();

private slots:
    void on_btnEnterData_clicked();

    void on_btnNextPoint_clicked();

    void on_btnExit_clicked();

private:
    std::vector<vector2D> points;
    Ui::CreatePolylineForm *ui;
};

#endif // CREATEPOLYLINEFORM_H
