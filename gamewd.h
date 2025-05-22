#ifndef GAMEWD_H
#define GAMEWD_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "myplane.h"
#include <QMouseEvent>
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"
#include "finish.h"

namespace Ui {
class GameWD;
}

class GameWD : public QWidget
{
    Q_OBJECT

public:
    explicit GameWD(QWidget *parent = nullptr);
    ~GameWD();

    void initScene();

    void playGame();

    void updatePos();

    void paintEvent(QPaintEvent*);

    void mouseMoveEvent(QMouseEvent*);

    void eneEmerge();

    void colliDetect();

    bool isFinish;

    EnemyPlane enemies[ENE_NUM];

    Bomb bombs[BOMB_NUM];

    int eneRecorder;

    Map map;

    MyPlane myPlane;

    QTimer timer;//定时器

    int score;

    Finish finisha;
    //Bullet temp_Bullet;
signals:
    void showFinish(int);
public slots:
    void recvGameWD();

private:
    Ui::GameWD *ui;
};

#endif // GAMEWD_H
