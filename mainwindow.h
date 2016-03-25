#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <roomclass.h>
#include <trespasclass.h>
#include <fireextclass.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void checkFire();
    void checkIntruder();

private:
    Ui::MainWindow *ui;
    RoomClass room;
    FireExtClass fireEx;
    TresPasClass tresPas;
private slots:
    void startFire();
    void addIntruder();
    void removeIntruder();
    void drawAll();
    void turnOnFire();
    void turnOffFire();
    void turnOnTres();
    void turnOffTres();
};

#endif // MAINWINDOW_H
