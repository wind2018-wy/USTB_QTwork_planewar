#ifndef FINISH_H
#define FINISH_H

#include <QWidget>

namespace Ui {
class Finish;
}

class Finish : public QWidget
{
    Q_OBJECT

public:
    explicit Finish(QWidget *parent = nullptr);
    ~Finish();
signals:
    void showGame();
public slots:
    void recvFinishSlot(int);
private slots:
    void on_restart_clicked();

private:
    Ui::Finish *ui;
};

#endif // FINISH_H
