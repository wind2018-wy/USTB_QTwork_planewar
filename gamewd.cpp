#include "gamewd.h"
#include "ui_gamewd.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <ctime>
#include <QSoundEffect>
#include <QMessageBox>
#include "finish.h"

GameWD::GameWD(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWD)
{
    isFinish=false;
    connect(this,&GameWD::showFinish,&finisha,&Finish::recvFinishSlot);
    ui->setupUi(this);
    for(int i=0;i<BULLET_NUM;i++){
        myPlane.bullets[i].free=true;
    }
    initScene();
}

GameWD::~GameWD()
{
    delete ui;
}

void GameWD::initScene()
{
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);
    setWindowIcon(QIcon(GAME_ICON));
    timer.setInterval(GAME_RATE);
    eneRecorder=0;
    //随机数种子
    srand((unsigned int)time(NULL));
}

void GameWD::playGame()
{
    QSoundEffect *soundEffect=new QSoundEffect;
    QUrl BKMurl=QUrl::fromLocalFile(QString::fromUtf8(SOUND_BACKGROUND));
    (*soundEffect).setSource(BKMurl);
    soundEffect->setVolume(0.5);
    soundEffect->setLoopCount(QSoundEffect::Infinite);
    (*soundEffect).play();

    for(int i=0;i<BULLET_NUM;i++){
        myPlane.bullets[i].free=true;
    }

    timer.start();
    connect(&timer,&QTimer::timeout,[=](){
        eneEmerge();
        updatePos();
        update();
        colliDetect();
    });
}

void GameWD::updatePos()
{
    map.mapPosition();

    myPlane.shoot();


    for(int i=0;i<BULLET_NUM;i++){
        if(myPlane.bullets[i].free==false){
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

void GameWD::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,map.map1_posY,map.map1);
    painter.drawPixmap(0,map.map2_posY,map.map2);

    painter.drawPixmap(myPlane.x,myPlane.y,myPlane.plane);

    for(int i=0;i<BULLET_NUM;i++){
        if(!myPlane.bullets[i].free){
            painter.drawPixmap(myPlane.bullets[i].x,myPlane.bullets[i].y,myPlane.bullets[i].myBullet);
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

void GameWD::mouseMoveEvent(QMouseEvent * event)
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

void GameWD::eneEmerge()
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

void GameWD::colliDetect()
{
    for(int i=0;i<ENE_NUM;i++){
        if(enemies[i].free)
            continue;
        if(enemies[i].rect.intersects(myPlane.rect)){
            emit showFinish(score);
            this->close();
            break;
        }
        for(int j=0;j<BULLET_NUM;j++){
            if(myPlane.bullets[j].free)
                continue;
            if(myPlane.bullets[j].myRect.intersects(enemies[i].rect)){
                // QSoundEffect *soundEffect=new QSoundEffect;
                // QUrl BKMurl=QUrl::fromLocalFile(QString::fromUtf8(SOUND_BOMB));
                // (*soundEffect).setSource(BKMurl);
                // soundEffect->setLoopCount(1);
                // (*soundEffect).play();
                score++;
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

void GameWD::recvGameWD()
{
    this->show();
    score=0;
    playGame();
}
