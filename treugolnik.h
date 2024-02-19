#ifndef TREUGOLNIK_H
#define TREUGOLNIK_H

#include "mainwindow.h"

class InputDialogTr : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogTr(QWidget *parent = nullptr);

    int getX();

private:
    QLineEdit *xInput;
};

class Treugolnik : public Mnogougolnik
{
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // TREUGOLNIK_H
