#ifndef CREATECIRCLEDIALOG_H
#define CREATECIRCLEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class createCircleDialog;
}

class createCircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createCircleDialog(QWidget *parent = nullptr);
    ~createCircleDialog();

signals:
    void sendCircleSignal(object::ptr obj, int mark);

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::createCircleDialog *ui;
};

#endif // CREATECIRCLEDIALOG_H
