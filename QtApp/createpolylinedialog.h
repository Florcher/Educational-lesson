#ifndef CREATEPOLYLINEDIALOG_H
#define CREATEPOLYLINEDIALOG_H

#include <QDialog>
#include "Objects.h"
#include <vector>

namespace Ui {
class CreatePolylineDialog;
}

class CreatePolylineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePolylineDialog(QWidget *parent = nullptr);
    ~CreatePolylineDialog();

    std::vector<vector2D> getPoints() const;

private slots:
    void on_btnNextPoint_clicked();

private:
    Ui::CreatePolylineDialog *ui;
    std::vector<vector2D> points;
};

#endif // CREATEPOLYLINEDIALOG_H
