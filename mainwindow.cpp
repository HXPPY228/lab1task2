#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    drawRectangle(false)
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
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(xInput);
    layout->addWidget(yInput);

    QPushButton *button = new QPushButton("OK", this);
    connect(button, SIGNAL(clicked()), this, SLOT(accept()));
    layout->addWidget(button);
}

InputDialog::~InputDialog()
{

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
    QRect wRect (600-x/2,450-y/2-100,x,y);
    painter.fillRect(wRect, Qt::green);
    }
}

void MainWindow::on_pryamougol_clicked()
{
        drawRectangle=true;
    InputDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        x = dialog.getX();
        y = dialog.getY();
    }
        this->update();

}


