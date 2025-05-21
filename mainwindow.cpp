#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "config.h"
#include "gamewd.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GameStart_clicked()
{
    connect(this,&MainWindow::showGameWD,&game,&GameWD::recvGameWD);
    emit showGameWD();
}

