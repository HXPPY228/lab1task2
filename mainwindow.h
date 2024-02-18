#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsItem>
#include <QDialog>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class Mnogougolnik : public QWidget
{

protected:
    Q_OBJECT
};

class IV_ugolnik : public Mnogougolnik
{

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pryamougol_clicked();

    void on_kvadrat_clicked();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::MainWindow *ui;
    bool drawRectangle, drawKvadrat;
    int x=0,y=0,xkv=0;

};

#endif // MAINWINDOW_H
