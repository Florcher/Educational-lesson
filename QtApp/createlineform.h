#ifndef CREATELINEFORM_H
#define CREATELINEFORM_H

#include <QWidget>
#include <QObject>
#include "Objects.h"
namespace Ui {
class CreateLineForm;
}


class CreateLineForm : public QWidget
{
     Q_OBJECT;
public:
    explicit CreateLineForm(QWidget *parent = nullptr);
    ~CreateLineForm();

signals:
    void signal(object::ptr obj);
    void signalExit();

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::CreateLineForm *ui;
};

#endif // CREATELINEFORM_H
