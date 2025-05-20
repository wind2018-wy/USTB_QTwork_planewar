#ifndef MAP_H
#define MAP_H

#include <QPixmap>

class Map
{
public:
    Map();
    void mapPosition();
public:
    QPixmap map1;
    QPixmap map2;

    int map1_posY;
    int map2_posY;

    int map_scroll_speed;
};

#endif // MAP_H
