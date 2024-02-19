#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    drawRectangle(false), drawKvadrat(false), drawTreugol(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *)
{
    if(drawRectangle&&x>0&&y>0)
    {
    QPainter painter(this);
    QRect wRect (100,100,x,y);
    painter.fillRect(wRect, Qt::green);
    QRect rRect (wRect.x()+wRect.width()/2,wRect.y()+wRect.height()/2,x/100,y/100);
    painter.fillRect(rRect, Qt::red);
    } else if (drawKvadrat&&xkv>0)
    {
        QPainter painter(this);
        QRect wRect (100,100,xkv,xkv);
        painter.fillRect(wRect, Qt::green);
        QRect rRect (wRect.x()+wRect.width()/2,wRect.y()+wRect.height()/2,xkv/100,xkv/100);
        painter.fillRect(rRect, Qt::red);
    } else if (drawTreugol&&xtr>0)
    {
        QPainter painter(this);
        QPolygon polygon;
        QPoint top(100+xtr/2, 100);
        QPoint left(100, 100+xtr*0.866);
        QPoint right(100+xtr, 100+xtr*0.866);
        polygon << top << left << right;
        painter.setBrush(Qt::green);
        painter.drawPolygon(polygon);
        QRect rRect (100+xtr/2,100+xtr*0.57735,xtr/100,xtr/100);
        painter.fillRect(rRect, Qt::red);
    }
}







