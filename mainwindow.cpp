#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <ctime>
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
    eneRecorder=0;
    //随机数种子
    srand((unsigned int)time(NULL));
}

void MainWindow::playGame()
{
    timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        eneEmerge();
        updatePos();
        update();
        colliDetect();
    });
}

void MainWindow::updatePos()
{
    map.mapPosition();

    myPlane.shoot();

    for(int i=0;i<BULLET_NUM;i++){
        if(!myPlane.bullets[i].free){
            myPlane.bullets[i].updatePosition();
        }
    }

    for(int i=0;i<ENE_NUM;i++){
        if(!enemies[i].free){
            enemies[i].updatePosition();
        }
    }

    for(int i=0;i<BOMB_NUM;i++){
        if(!bombs[i].free){
            bombs[i].updateInfo();
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
        if(!myPlane.bullets[i].free){
            painter.drawPixmap(myPlane.bullets[i].x,myPlane.bullets[i].y,myPlane.bullets[i].myBullet1);
        }
    }

    for(int i=0;i<ENE_NUM;i++){
        if(!enemies[i].free){
            painter.drawPixmap(enemies[i].x,enemies[i].y,enemies[i].enemy);
        }
    }

    for(int i=0;i<BOMB_NUM;i++){
        if(!bombs[i].free){
            painter.drawPixmap(bombs[i].x,bombs[i].y,bombs[i].pixarr[bombs[i].index]);
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

void MainWindow::eneEmerge()
{
    eneRecorder++;
    if(eneRecorder<ENE_INTERVAL)
        return;
    eneRecorder=0;
    for(int i=0;i<ENE_NUM;i++){
        if(enemies[i].free){
            enemies[i].x=rand()%(GAME_WIDTH-enemies[i].enemy.width());
            enemies[i].y=-enemies[i].enemy.height();
            enemies[i].free=false;
            break;
        }
    }
}

void MainWindow::colliDetect()
{
    for(int i=0;i<ENE_NUM;i++){
        if(enemies[i].free)
            continue;
        for(int j=0;j<BULLET_NUM;j++){
            if(myPlane.bullets[i].free)
                continue;
            if(myPlane.bullets[j].myRect1.intersects(enemies[i].rect)){
                myPlane.bullets[j].free=true;
                enemies[i].free=true;
                for(int k=0;k<BOMB_NUM;k++){
                    if(bombs[k].free){
                        bombs[k].free=false;
                        bombs[k].x=enemies[i].x;
                        bombs[k].y=enemies[i].y;
                        break;
                    }
                }
            }
        }
    }
}
