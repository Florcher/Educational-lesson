#ifndef CREATECIRCLEDIALOG_H
#define CREATECIRCLEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class CreateCircleDialog;
}

class CreateCircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateCircleDialog(QWidget *parent = nullptr);
    ~CreateCircleDialog();

    vector2D getCenter() const;
    double getRadius() const;

private:
    Ui::CreateCircleDialog *ui;
};

#endif // CREATECIRCLEDIALOG_H
