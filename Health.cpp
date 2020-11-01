#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initializes health to 100
    health = 100;

    //shows the score
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 20)); //(font name, font size)
}

void Health::decrease()
{
    health = health - 50;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

