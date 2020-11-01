#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //initializes score to zero
    score = 0;

    //shows the score
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 20)); //(font name, font size)
}

void Score::increase()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}

