#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "map.h"
#include "myplane.h"
#include <QMouseEvent>
#include "bullet.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initScene();

    void playGame();

    void updatePos();

    void paintEvent(QPaintEvent*);

    void mouseMoveEvent(QMouseEvent*);

    Map map;

    MyPlane myPlane;

    QTimer timer;//定时器

    //Bullet temp_Bullet;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
