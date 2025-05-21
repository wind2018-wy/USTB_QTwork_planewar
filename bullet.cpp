#include "bullet.h"
#include "config.h"
#include <QDebug>

Bullet::Bullet() {
    myBullet1.load(MY_BULLET_PATH);
    myBullet2.load(MY_BULLET_PATH2);
    myBullet3.load(MY_BULLET_PATH3);

    QSize specificSize(18, 42);
    QPixmap scaledPixmap = myBullet1.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    myBullet1=scaledPixmap;
    scaledPixmap = myBullet2.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    myBullet2=scaledPixmap;
    scaledPixmap = myBullet3.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    myBullet3=scaledPixmap;

    x=(GAME_WIDTH-myRect1.width())*0.5;
    y=GAME_HEIGHT;
    free=true;
    speed=MY_BULLET_SPEED;

    myRect1.setWidth(myBullet1.width());
    myRect1.setHeight(myBullet1.height());
    myRect1.moveTo(x,y);
    myRect2.setWidth(myBullet2.width());
    myRect2.setHeight(myBullet2.height());
    myRect2.moveTo(x,y);
    myRect3.setWidth(myBullet3.width());
    myRect3.setHeight(myBullet3.height());
    myRect3.moveTo(x,y);
}

void Bullet::updatePosition()
{
    if(free)
        return;
    y-=MY_BULLET_SPEED;
    myRect1.moveTo(x,y);
    myRect2.moveTo(x,y);
    myRect3.moveTo(x,y);
    if(y<=-myRect1.height()){
        free=true;
    }
    if(y<=-myRect2.height()){
        free=true;
    }
    if(y<=-myRect3.height()){
        free=true;
    }
    //qDebug()<<QString::number(x)<<"   "<<QString::number(y);
}
