#include "MyRect.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0) //this will not let the player go outside the screen and disappear
        {
            setPos(x() - 10, y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 800) //this will not let the player go outside the screen and disappear
        {
            setPos(x() + 10, y());
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        //creates a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);
    }
}

void MyRect::spawn()
{
    //creates an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
