#ifndef ERRORFORM_H
#define ERRORFORM_H

#include <QWidget>

namespace Ui {
class ErrorForm;
}

class ErrorForm : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorForm(QWidget *parent = nullptr);
    ~ErrorForm();

private slots:
    void on_btnExit_clicked();

signals :
    void signalExit();

private:
    Ui::ErrorForm *ui;
};

#endif // ERRORFORM_H
