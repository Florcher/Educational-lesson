#ifndef CREATELINEDIALOG_H
#define CREATELINEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class createlineDialog;
}

class createlineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createlineDialog(QWidget *parent = nullptr);
    ~createlineDialog();

signals:
    void sendLineSignal(object::ptr obj, int mark);

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

private:
    Ui::createlineDialog *ui;
};

#endif // CREATELINEDIALOG_H
