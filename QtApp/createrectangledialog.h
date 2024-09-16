#ifndef CREATERECTANGLEDIALOG_H
#define CREATERECTANGLEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class CreateRectangleDialog;
}

class CreateRectangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRectangleDialog(QWidget *parent = nullptr);
    ~CreateRectangleDialog();

    vector2D getLeftDownPoint() const;
    double getLenth() const;
    double getWidth() const;

private:
    Ui::CreateRectangleDialog *ui;
};

#endif // CREATERECTANGLEDIALOG_H
