#include "kvadrat.h"
#include "ui_mainwindow.h"

InputDialogKv::InputDialogKv(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение x в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

int InputDialogKv::getX()
{
    return xInput->text().toInt();
}

void MainWindow::on_kvadrat_clicked()
{
    drawKvadrat=true;
    drawRectangle=false;
    drawTreugol=false;
    InputDialogKv dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        xkv = dialog.getX();
    }
    if (xkv<=0){
        ui->label_2->setText("Ошибка!");
    } else{
    this->update();
    QString S = QString::number(xkv*xkv);
    QString P = QString::number((xkv+xkv)*2);
    ui->label_2->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс помечен красной точкой.");
    }
    }
