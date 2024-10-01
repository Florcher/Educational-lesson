#ifndef CREATECIRCLEFORM_H
#define CREATECIRCLEFORM_H

#include <QWidget>
#include "Objects.h"

namespace Ui {
class CreateCircleForm;
}

class CreateCircleForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreateCircleForm(QWidget *parent = nullptr);
    ~CreateCircleForm();

signals:
    void signal(object::ptr obj);
    void signalExit();

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::CreateCircleForm *ui;
};

#endif // CREATECIRCLEFORM_H
