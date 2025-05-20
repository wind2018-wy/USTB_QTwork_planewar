#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initScene();
    playGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    timer.setInterval(GAME_RATE);
}

void MainWindow::playGame()
{
    timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        updatePos();
        update();
    });
}

void MainWindow::updatePos()
{
    map.mapPosition();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);
}
