#ifndef CREATEPOLYLINEDIALOG_H
#define CREATEPOLYLINEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class createPolylineDialog;
}

class createPolylineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit createPolylineDialog(QWidget *parent = nullptr);
    ~createPolylineDialog();

signals:
    void sendPolylineSignal(object::ptr obj, int mark);

private slots:
    void on_btnEnterData_clicked();

    void on_btnExit_clicked();

    void on_btnNextPoint_clicked();

private:
    std::vector<vector2D> points;
    Ui::createPolylineDialog *ui;
};

#endif // CREATEPOLYLINEDIALOG_H
