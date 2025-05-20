#include "mainwindow.h"

#include "config.h"
#include <QApplication>
#include <QResource>

int main(int argc, char *argv[])
{
    //QResource::registerResource(GAME_RES_PATH);//注册二进制资源信息

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
