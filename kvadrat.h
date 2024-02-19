#ifndef KVADRAT_H
#define KVADRAT_H

#include "pryamougolnik.h"

class InputDialogKv : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogKv(QWidget *parent = nullptr);

    int getX();

private:
    QLineEdit *xInput;
};

class Kvadrat : public Pryamougolnik
{
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // KVADRAT_H
