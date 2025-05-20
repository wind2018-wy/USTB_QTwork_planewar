#include "enemyplane.h"
#include "config.h"
#include <QRect>

EnemyPlane::EnemyPlane() {
    enemy.load(ENE_PLANE_PATH);

    QSize specificSize(62, 44);

    QPixmap scaledPixmap = enemy.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    enemy=scaledPixmap;

    x=0;y=0;
    free=true;
    speed=ENE_PLANE_SPEED;

    rect.setWidth(enemy.width());
    rect.setHeight(enemy.height());
    rect.moveTo(x,y);
}

void EnemyPlane::updatePosition(){
    if(free)
        return;

    y+=speed;
    rect.moveTo(x,y);
    if(y>=GAME_HEIGHT+enemy.height()){
        free=true;
    }
}
