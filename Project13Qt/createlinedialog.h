#ifndef CREATELINEDIALOG_H
#define CREATELINEDIALOG_H

#include <QDialog>
#include "Objects.h"

namespace Ui {
class CreateLineDialog;
}

class CreateLineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateLineDialog(QWidget *parent = nullptr);
    ~CreateLineDialog();

    vector2D getStartPoint() const;
    vector2D getEndPoint() const;

private:
    Ui::CreateLineDialog *ui;
};

#endif // CREATELINEDIALOG_H
