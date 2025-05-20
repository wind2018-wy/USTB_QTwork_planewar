#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
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

    myPlane.shoot();

    for(int i=0;i<BULLET_NUM;i++){
        if(myPlane.bullets[i].free==false){
            myPlane.bullets[i].updatePosition();
        }
    }
    // temp_Bullet.free=false;
    // temp_Bullet.updatePosition();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);

    painter.drawPixmap(myPlane.x,myPlane.y,myPlane.plane);

    for(int i=0;i<BULLET_NUM;i++){
        if(myPlane.bullets[i].free==false){
            painter.drawPixmap(myPlane.bullets[i].x,myPlane.bullets[i].y,myPlane.bullets[i].myBullet1);
        }
    }
    //painter.drawPixmap(temp_Bullet.x,temp_Bullet.y,temp_Bullet.myBullet1);
}

void MainWindow::mouseMoveEvent(QMouseEvent * event)
{
    int x=event->x()-myPlane.rect.width()*0.5;
    int y=event->y()-myPlane.rect.height()*0.5;

    if(x<=0){
        x=0;
    }
    if(x>=GAME_WIDTH-myPlane.rect.width())
        x=GAME_WIDTH-myPlane.rect.width();
    if(y<= 0)
        y=0;
    if(y >= GAME_HEIGHT -myPlane.rect.height())
        y=GAME_HEIGHT-myPlane.rect.height();

    myPlane.setPosition(x,y);
}
