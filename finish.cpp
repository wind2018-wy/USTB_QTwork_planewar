#include "finish.h"
#include "ui_finish.h"

Finish::Finish(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Finish)
{
    ui->setupUi(this);
}

Finish::~Finish()
{
    delete ui;
}

void Finish::recvFinishSlot(int score)
{
    ui->scoreLabel->setNum(score);
    this->show();
}

void Finish::on_restart_clicked()
{
    this->hide();
}

