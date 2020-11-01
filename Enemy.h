#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy:  public QObject, public QGraphicsPixmapItem  //If you are using multiple inheritance, moc assumes that the first inherited class is a subclass of QObject. Also, be sure that only the first inherited class is a QObject.
{
    Q_OBJECT //adding a macro
    public:
        Enemy(QGraphicsPixmapItem  *parent = 0);

    public slots:
        void move();

};

#endif // ENEMY_H
