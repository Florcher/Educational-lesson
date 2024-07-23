#ifndef ERRORDATADIALOG_H
#define ERRORDATADIALOG_H

#include <QDialog>

namespace Ui {
class ErrorDataDialog;
}

class ErrorDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorDataDialog(QWidget *parent = nullptr);
    ~ErrorDataDialog();

private slots:
    void on_btnExit_clicked();

private:
    Ui::ErrorDataDialog *ui;
};

#endif // ERRORDATADIALOG_H
