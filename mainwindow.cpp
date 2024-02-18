#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    drawRectangle(false), drawKvadrat(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

int InputDialog::getX()
{
    return xInput->text().toInt();
}

int InputDialog::getY()
{
    return yInput->text().toInt();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    if(drawRectangle)
    {
    QPainter painter(this);
    QRect wRect (600-x/2,350-y/2,x,y);
    painter.fillRect(wRect, Qt::green);
    QRect rRect (wRect.x()+wRect.width()/2,wRect.y()+wRect.height()/2,x/100,y/100);
    painter.fillRect(rRect, Qt::red);
    } else if (drawKvadrat)
    {
        QPainter painter(this);
        QRect wRect (600-xkv/2,350-xkv/2,xkv,xkv);
        painter.fillRect(wRect, Qt::green);
        QRect rRect (wRect.x()+wRect.width()/2,wRect.y()+wRect.height()/2,xkv/100,xkv/100);
        painter.fillRect(rRect, Qt::red);
    }



}

void MainWindow::on_pryamougol_clicked()
{
        drawRectangle=true;
        drawKvadrat=false;
    InputDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        x = dialog.getX();
        y = dialog.getY();
    }
    this->update();
    QString S = QString::number(x*y);
    QString P = QString::number((x+y)*2);
    ui->label_2->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс помечен красной точкой.");
}



void MainWindow::on_kvadrat_clicked()
{
    drawKvadrat=true;
    drawRectangle=false;
    InputDialogKv dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        xkv = dialog.getX();
    }
    this->update();
    QString S = QString::number(xkv*xkv);
    QString P = QString::number((xkv+xkv)*2);
    ui->label_2->setText("Площадь в пикселях: " + S + ". Периметр в пикселях: " + P + ". Центр масс помечен красной точкой.");
}

