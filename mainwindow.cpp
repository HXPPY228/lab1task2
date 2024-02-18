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







