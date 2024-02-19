#include "pryamougolnik.h"
#include "ui_mainwindow.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this)),
    yInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение x в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QHBoxLayout *yLayout = new QHBoxLayout;
    QLabel *yLabel = new QLabel("Введите значение y в пикселях: ", this);
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yInput);
    mainLayout->addLayout(yLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

int InputDialog::getX()
{
    return xInput->text().toInt();
}

int InputDialog::getY()
{
    return yInput->text().toInt();
}

void MainWindow::on_pryamougol_clicked()
{
    drawRectangle=true;
    drawKvadrat=false;
    drawTreugol=false;
    InputDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        x = dialog.getX();
        y = dialog.getY();
    }
    if (x<=0||y<=0){
        ui->label_2->setText("Ошибка!");
    } else{
    this->update();
    QString S = QString::number(x*y);
    QString P = QString::number((x+y)*2);
    ui->label_2->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс помечен красной точкой.");
}
}
