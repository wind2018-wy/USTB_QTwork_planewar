#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include <QPixmap>
#include <QRect>

class EnemyPlane
{
public:
    EnemyPlane();
    void updatePosition();
public:
    QPixmap enemy;
    int x,y;
    QRect rect;
    bool free;
    int speed;
};

#endif // ENEMYPLANE_H
