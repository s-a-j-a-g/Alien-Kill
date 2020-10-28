#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy:  public QObject, public QGraphicsRectItem //If you are using multiple inheritance, moc assumes that the first inherited class is a subclass of QObject. Also, be sure that only the first inherited class is a QObject.
{
    Q_OBJECT //adding a macro
    public:
        Enemy();

    public slots:
        void move();

};

#endif // ENEMY_H
