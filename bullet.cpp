#include "bullet.h"
#include "config.h"
#include <QDebug>

Bullet::Bullet() {
    myBullet.load(MY_BULLET_PATH);
    // myBullet2.load(MY_BULLET_PATH2);
    // myBullet3.load(MY_BULLET_PATH3);

    QSize specificSize(18, 42);
    QPixmap scaledPixmap = myBullet.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    myBullet=scaledPixmap;
    // scaledPixmap = myBullet2.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    // myBullet2=scaledPixmap;
    // scaledPixmap = myBullet3.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    // myBullet3=scaledPixmap;

    x=(GAME_WIDTH-myRect.width())*0.5;
    y=GAME_HEIGHT;
    free=true;
    speed=MY_BULLET_SPEED;

    myRect.setWidth(myBullet.width());
    myRect.setHeight(myBullet.height());
    myRect.moveTo(x,y);
}

void Bullet::updatePosition()
{
    if(free)
        return;
    y-=MY_BULLET_SPEED;
    myRect.moveTo(x,y);
    if(y<=-myRect.height()){
        free=true;
    }
    //qDebug()<<QString::number(x)<<"   "<<QString::number(y);
}
