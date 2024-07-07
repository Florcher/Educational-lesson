#ifndef CREATERECTANGLEDIALOG_H
#define CREATERECTANGLEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class createRectangleDialog;
}

class createRectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createRectangleDialog(QWidget *parent = nullptr);
    ~createRectangleDialog();

signals:
    void sendRectangleSignal(object::ptr obj, int mark);

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::createRectangleDialog *ui;
};

#endif // CREATERECTANGLEDIALOG_H
