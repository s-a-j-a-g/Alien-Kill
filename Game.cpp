#include "Game.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaPlaylist>

Game::Game(QWidget *parent)
{
    //creates a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    setBackgroundBrush(QBrush(QImage(":/images/bgimage.jpg")));

    //makes the newly created 'scene' the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //disables Scroll Bar
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //disables Scroll Bar
    setFixedSize(800, 800);

    //creates a player to put into the scene
    Player *player = new Player();
    //player->setRect(0, 0, 100, 100);
    //player->setPos((scene->width())/2 - 50, scene->height() - player->rect().height());
    player->setPos(350, 550);

    //makes the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //adds the player to the scene
    scene->addItem(player);

    //makes the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //creates score and health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y() + 35);
    scene->addItem(health);

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000); //creates enemy every 2 seconds

    // play background music
    QMediaPlayer *bgmusic = new QMediaPlayer();
    bgmusic->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    bgmusic->play();

//    QMediaPlaylist * playlist = new QMediaPlaylist();
//        playlist->addMedia(QUrl("qrc:/sounds/bgsound.mp3"));
//        playlist->setPlaybackMode(QMediaPlaylist::Loop);

    show();
}
