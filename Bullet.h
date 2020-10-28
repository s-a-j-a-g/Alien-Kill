#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet:  public QObject, public QGraphicsRectItem //If you are using multiple inheritance, moc assumes that the first inherited class is a subclass of QObject. Also, be sure that only the first inherited class is a QObject.
{
    Q_OBJECT //adding a macro
    public:
        Bullet();

    public slots:
        void move();

};

#endif // BULLET_H
