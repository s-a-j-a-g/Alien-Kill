#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game; //meaning that there is an external global object called 'game'

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
//    //creates a rectangle(bullet)
//    setRect(0, 0, 10, 50);

    //draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30); //30 ms
}

void Bullet::move()
{
    /////if bullet collides with enemy, destroy both\\\\\
    //QGraphicsItem has a member function called collidingItems() which returns a list of all the items that are colliding with the calling object
    QList<QGraphicsItem *> colliding_items = collidingItems(); //this statement will store a list of pointers to all the QGraphicsItem that the calling object is colliding with
    int n = colliding_items.size();
    for(int i = 0; i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase the score
            game->score->increase();

            //removes them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //deletes them both
            delete colliding_items[i];
            delete this;
            return; //after collision bullet should not move upwards because it has already been deleted
        }
    }

    //bullet moves up
    setPos(x(), y() - 10);

    if(pos().y() < 0) //+ rect().height() < 0) //here rect().height()  50 //when the bottom part of a bullet passes the x- axis, memory is freed
    {
        scene()->removeItem(this);
        delete this;
    }
}
