#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "roomclass.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fireEx.setRoom(&room);
    tresPas.setRoom(&room);

    connect(ui->fireButton, SIGNAL(clicked()),
            this, SLOT(startFire()));
    connect(ui->onFButton, SIGNAL(clicked()),
            this, SLOT(turnOnFire()));
    connect(ui->offFButton, SIGNAL(clicked()),
            this, SLOT(turnOffFire()));
    connect(ui->onTresButton, SIGNAL(clicked()),
            this, SLOT(turnOnTres()));
    connect(ui->offTresButton, SIGNAL(clicked()),
            this, SLOT(turnOffTres()));
    connect(ui->intruderButton, SIGNAL(clicked()),
            this, SLOT(addIntruder()));
    connect(ui->removeIntruderButton, SIGNAL(clicked()),
            this, SLOT(removeIntruder()));
    drawAll();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::startFire()
{
    room.setOnFire(1);
    drawAll();
    qApp->processEvents();
    QThread::sleep(1);
    checkFire();
}

void MainWindow::addIntruder()
{
    room.intrude(1);
    ui->intruder->setText("D");
    drawAll();
    qApp->processEvents();
    QThread::sleep(1);
    checkIntruder();
}

void MainWindow::removeIntruder()
{
    room.intrude(0);
    ui->intruder->setText("_");
    drawAll();
}

void MainWindow::checkFire()
{
    if (fireEx.fireDetected())
    {
        fireEx.activateSprinklers(1);
        drawAll();
        ui->textEdit->append("Warning! Your house is on fire!");
        qApp->processEvents();
        QThread::sleep(1);
        room.setOnFire(0);
        drawAll();
        qApp->processEvents();
        QThread::sleep(1);
        fireEx.activateSprinklers(0);
        drawAll();
    }
    else fireEx.activateSprinklers(0);
    drawAll();
}



void MainWindow::drawAll()
{
    if (room.isBurning()) ui->fireLabel->setText("_11_");
    if (!room.isBurning()) ui->fireLabel->setText("____");

    if (fireEx.isSprinkling()) ui->sprinkLabel->setText("1111");
    if (!fireEx.isSprinkling()) ui->sprinkLabel->setText("----");
    if (fireEx.isOn()) ui->fireExLabel->setText("1");
    else ui->fireExLabel->setText("0");

    if (room.isIntruded()) ui->intruder->setText("D");
    if (!room.isIntruded()) ui->intruder->setText("_");
    if (tresPas.isOn()) ui->tresPasLabel->setText("1");
    else ui->tresPasLabel->setText("0");
}

void MainWindow::turnOnFire()
{
    fireEx.toggle(1);
    drawAll();
    checkFire();
}

void MainWindow::turnOffFire()
{
    fireEx.toggle(0);
    fireEx.activateSprinklers(0);
    drawAll();
}

void MainWindow::turnOnTres()
{
    tresPas.toggle(1);
    checkIntruder();
    drawAll();
}

void MainWindow::turnOffTres()
{
    tresPas.toggle(0);
    drawAll();
}

void MainWindow::checkIntruder()
{
    if (tresPas.intruderDetected() && tresPas.isOn())
    {
        ui->textEdit->append("Warning! An intruder detected!");
    }
}
