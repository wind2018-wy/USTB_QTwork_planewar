#include "myplane.h"
#include "config.h"

MyPlane::MyPlane() {
    plane.load(MY_PLANE_PATH);
    QSize specificSize(80, 60);

    QPixmap scaledPixmap = plane.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    plane=scaledPixmap;

    x=(GAME_WIDTH-plane.width())*0.5;
    y=GAME_HEIGHT-plane.height();

    rect.setWidth(plane.width());
    rect.setHeight(plane.height());
    rect.moveTo(x,y);
}

void MyPlane::shoot()
{
    recorder++;
    if(recorder<BULLET_INTERVAL)
        return;
    recorder=0;
    for(int i=0;i<BULLET_NUM;i++){
        if(bullets[i].free){
            bullets[i].x=x+(rect.width()-bullets[i].myRect1.width())*0.5;
            bullets[i].y=y;
            bullets[i].free=false;
            break;
        }
    }
}

void MyPlane::setPosition(int a,int b){
    x=a;y=b;
    rect.moveTo(x,y);
}
