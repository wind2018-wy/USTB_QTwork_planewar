#ifndef MYPLANE_H
#define MYPLANE_H

#include <QPixmap>
#include <QRect>

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
};

#endif // MYPLANE_H
