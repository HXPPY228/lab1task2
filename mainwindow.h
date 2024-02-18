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

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);

    int getX();
    int getY();

private:
    QLineEdit *xInput, *yInput;
};

class InputDialogKv : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialogKv(QWidget *parent = nullptr);

    int getX();

private:
    QLineEdit *xInput;
};

class Mnogougolnik : public QWidget
{

protected:
    Q_OBJECT
};

class IV_ugolnik : public Mnogougolnik
{

};

class Pryamougolnik : public IV_ugolnik
{
protected:
    void paintEvent(QPaintEvent *) override;
};

class Kvadrat : public Pryamougolnik
{
protected:
    void paintEvent(QPaintEvent *) override;
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
    int x,y,xkv;

};




#endif // MAINWINDOW_H
