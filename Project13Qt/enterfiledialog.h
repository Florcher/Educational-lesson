#ifndef ENTERFILEDIALOG_H
#define ENTERFILEDIALOG_H

#include <QDialog>
#include "DataBase.h"
namespace Ui {
class EnterFileDialog;
}

class EnterFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EnterFileDialog(QWidget *parent = nullptr);
    ~EnterFileDialog();

signals:
    void enterDatasignal(DataBase::ptr db);

private slots:
    void on_btnEnterData_clicked();

private:
    Ui::EnterFileDialog *ui;
};

#endif // ENTERFILEDIALOG_H
