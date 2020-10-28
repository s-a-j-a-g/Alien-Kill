#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating a scene
    QGraphicsScene  *scene = new QGraphicsScene();

    //creating an item to put into the scene
    MyRect *player = new MyRect();
    player->setRect(0, 0, 100, 100);

    //adding the item to the scene
    scene->addItem(player);

    //making rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //adding a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //disables Scroll Bar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //disables Scroll Bar
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);
    player->setPos((view->width())/2 - 50, view->height() - player->rect().height());
    view->show();

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000); //creates enemy every 2 seconds

    return a.exec();
}

