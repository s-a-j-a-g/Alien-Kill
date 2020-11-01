#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:sounds/fire.mp3"));

    //draw graphics
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
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

        //plays bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
            bulletsound->play();
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    //creates an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
