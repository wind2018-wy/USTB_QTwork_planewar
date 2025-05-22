#ifndef MYPLANE_H
#define MYPLANE_H

#include <QPixmap>
#include <QRect>
#include "config.h"
#include "bullet.h"

class MyPlane
{
public:
    MyPlane();
    void shoot();
    void setPosition(int,int);
public:
    QPixmap plane;//飞机资源

    int x,y;

    QRect rect;//矩形边框

    Bullet bullets[BULLET_NUM];
    int recorder;//发射间隔记录
};

#endif // MYPLANE_H
