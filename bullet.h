#ifndef BULLET_H
#define BULLET_H

#include "config.h"
#include <QPixmap>
#include <QRect>
class Bullet
{
public:
    Bullet();

    void updatePosition();
public:
    QPixmap myBullet1,myBullet2,myBullet3;
    QPixmap eneBullet1;

    int x,y;

    int speed;

    bool free;//子弹是否闲置

    QRect myRect1,myRect2,myRect3;
    QRect eneRect1;
};

#endif // BULLET_H
