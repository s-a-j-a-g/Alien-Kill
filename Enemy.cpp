#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

Enemy::Enemy()
{
    //creates a rectangle(enemy)
    setRect(0, 0, 50, 50);

    //sets random position
    int random_number = rand() % 750;
    setPos(random_number, 0);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); //50 ms
}

void Enemy::move()
{
    //enemy moves down
    setPos(x(), y() + 5);

    if(pos().y() > 600) //here rect().height()  50 //when the top part of an enemy passes the scene, memory is freed
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "DELETED!!!!!!";
    }
}
