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

void MyPlane::setPosition(int a,int b){
    x=a;y=b;
    rect.moveTo(x,y);
}
