#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem //If you are using multiple inheritance, moc assumes that the first inherited class is a subclass of QObject. Also, be sure that only the first inherited class is a QObject.
{
    Q_OBJECT //adding a macro
    public:
        Bullet(QGraphicsItem *parent = 0);

    public slots:
        void move();

};

#endif // BULLET_H
