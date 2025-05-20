#include "bomb.h"
#include "config.h"
#include <QString>

Bomb::Bomb() {
    for(int i=1;i<=BOMB_NUM;i++){
        QString str=QString(BOMB_PATH).arg(i);
        QPixmap strr=QPixmap(str);
        QSize specificSize(62, 44);

        QPixmap scaledPixmap = strr.scaled(specificSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        strr=scaledPixmap;
        pixarr.push_back(strr);
    }
    x=0;
    y=0;
    free=true;
    index=0;
    recorder=0;
}

void Bomb::updateInfo()
{
    if(free)
        return;
    recorder++;
    if(recorder<BOMB_INTERVAL)
        return;
    recorder=0;
    index++;
    if(index>BOMB_MAX-1){
        index=0;
        free=true;
    }
}
