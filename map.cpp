#include "map.h"
#include "config.h"

Map::Map() {
    map1.load(MAP1_PATH);
    map2.load(MAP1_PATH);

    map1_posY=-GAME_HEIGHT;
    map2_posY=0;

    map_scroll_speed=MAP_SCROLL_SPEED;
}

void Map::mapPosition(){
    map1_posY++;
    map2_posY++;
    if(map1_posY>=0)
        map1_posY=-GAME_HEIGHT;
    if(map2_posY>=GAME_HEIGHT)
        map2_posY=0;
}
