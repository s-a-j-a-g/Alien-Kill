#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "Game.h"

extern Game *game;

Enemy::Enemy(QGraphicsPixmapItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    //creates a rectangle(enemy)
    //setRect(0, 0, 50, 50);

    //draw graphics
    setPixmap(QPixmap(":/images/enemy.png"));

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

    if(pos().y() > 800) //here rect().height()  50 //when the top part of an enemy passes the scene, memory is freed //and health is reduced
    {
        scene()->removeItem(this);
        delete this;

        game->health->decrease();
    }
}
