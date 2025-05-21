#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewd.h"

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
    GameWD game;
private slots:
    void on_GameStart_clicked();
signals:
    void showGameWD();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
