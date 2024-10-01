#ifndef CREATERECTANGLEFORM_H
#define CREATERECTANGLEFORM_H

#include <QWidget>
#include "Objects.h"

namespace Ui {
class CreateRectangleForm;
}

class CreateRectangleForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateRectangleForm(QWidget *parent = nullptr);
    ~CreateRectangleForm();

signals:
    void signal(object::ptr obj);
    void signalExit();

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::CreateRectangleForm *ui;
};

#endif // CREATERECTANGLEFORM_H
