#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QPixmap>
#include <Qvector>

class Bomb
{
public:
    Bomb();
    //更新信息（下标，间隔）
    void updateInfo();
public:
    QVector<QPixmap>pixarr;

    int x,y;
    bool free;
    int recorder;
    int index;
};

#endif // BOMB_H
