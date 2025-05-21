#include "myplane.h"
#include "config.h"
#include <QDebug>

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
    for(int i=0;i<BULLET_NUM;i++){
        bullets1[i].free=true;
        bullets2[i].free=true;
        bullets3[i].free=true;
    }
}

void MyPlane::shoot()
{
    qDebug()<<"fashe";
    recorder++;
    if(recorder<BULLET_INTERVAL)
        return;
    recorder=0;
    for(int i=0;i<BULLET_NUM;i++){
        if(bullets1[i].free){
            bullets1[i].x=x+(rect.width()-bullets1[i].myRect1.width())*0.5;
            bullets1[i].y=y;
            bullets1[i].free=false;
            break;
        }
    }
    for(int i=0;i<BULLET_NUM;i++){
        if(bullets2[i].free){
            bullets2[i].x=x;
            bullets2[i].y=y;
            bullets2[i].free=false;
            break;
        }
    }
    for(int i=0;i<BULLET_NUM;i++){
        if(bullets3[i].free){
            bullets3[i].x=x+(rect.width()-bullets3[i].myRect3.width());
            bullets3[i].y=y;
            bullets3[i].free=false;
            break;
        }
    }
}

void MyPlane::setPosition(int a,int b){
    x=a;y=b;
    rect.moveTo(x,y);
}
