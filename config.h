#ifndef CONFIG_H
#define CONFIG_H

//游戏配置
#define GAME_WIDTH 512
#define GAME_HEIGHT 768
#define GAME_TITLE "thunder plane"
#define GAME_RES_PATH "plane.rcc"
#define GAME_ICON ":/picture/my_plane_1"
#define GAME_RATE 10     //帧率 毫秒

//地图配置
#define MAP1_PATH ":/picture/game_map_1"
#define MAP_SCROLL_SPEED 2

//飞机配置
#define MY_PLANE_PATH ":/picture/my_plane_1"


#define ENE_PLANE_PATH ":/picture/ene_plane_1"
#define ENE_NUM 20
#define ENE_INTERVAL 30
#define ENE_PLANE_SPEED 5

//子弹配置
#define MY_BULLET_PATH ":/picture/bullet_1"
#define MY_BULLET_PATH2 ":/picture/bullet_2"
#define MY_BULLET_PATH3 ":/picture/bullet_3"

#define MY_BULLET_SPEED 5

#define ENE_BULLET_PATH ":/picture/bullet_1r"
#define ENE_BULLET_PATH2 ":/picture/bullet_2r"
#define ENE_BULLET_PATH3 ":/picture/bullet_3r"

#define ENE_BULLET_SPEED 4

#define BULLET_NUM 30
#define BULLET_INTERVAL 20

//爆炸效果
#define BOMB_PATH ":/picture/explo_1_%1"
#define BOMB_NUM 20//爆炸数量
#define BOMB_MAX 4//爆炸图片最大索引
#define BOMB_INTERVAL 20//爆炸切图时间间隔

//音效
#define SOUND_BACKGROUND ":/picture/BGmusic.wav"
#define SOUND_BOMB ":/picture/BombM.wav"
#endif // CONFIG_H
