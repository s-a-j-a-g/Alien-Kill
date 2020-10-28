#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT //adding a macro
    public:
        void keyPressEvent(QKeyEvent *event);

    public slots:
        void spawn();
};

#endif // MYRECT_H
