#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"

Bullet::Bullet()
{
    //creates a rectangle(bullet)
    setRect(0, 0, 10, 50);

    //connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); //50 ms
}

void Bullet::move()
{
    //if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_items[i];
            delete this;
            return; //after collision bullet should not move upwards because it has already been deleted
        }
    }

    //bullet moves up
    setPos(x(), y() - 10);

    if(pos().y() + rect().height() < 0) //here rect().height()  50 //when the bottom part of a bullet passes the x- axis, memory is freed
    {
        scene()->removeItem(this);
        delete this;
    }
}
