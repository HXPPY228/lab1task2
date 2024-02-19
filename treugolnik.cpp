#include "treugolnik.h"
#include "ui_mainwindow.h"

    InputDialogTr::InputDialogTr(QWidget *parent) :
    QDialog(parent),
    xInput(new QLineEdit(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    QLabel *xLabel = new QLabel("Введите значение стороны в пикселях: ", this);
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xInput);
    mainLayout->addLayout(xLayout);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    mainLayout->addWidget(button);
}

int InputDialogTr::getX()
{
    return xInput->text().toInt();
}

void MainWindow::on_treugol_clicked()
{
    drawTreugol=true;
    drawKvadrat=false;
    drawRectangle=false;
    InputDialogTr dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        xtr = dialog.getX();
    }
    if (xtr<=0){
        ui->label_2->setText("Ошибка!");
    } else{
        this->update();
        QString S = QString::number(xtr*xtr*0.433);
        QString P = QString::number(xtr*3);
        ui->label_2->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс помечен красной точкой.");
    }
}
