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
    QPixmap myBullet;
    QPixmap eneBullet;

    int x,y;

    int speed;

    bool free;

    QRect myRect;
    QRect eneRect;
};

#endif // BULLET_H
