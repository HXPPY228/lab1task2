#ifndef PRYAMOUGOLNIK_H
#define PRYAMOUGOLNIK_H

#include "mainwindow.h"

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QLineEdit *xInput, *yInput;
};

class Pryamougolnik : public IV_ugolnik
{
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // PRYAMOUGOLNIK_H
