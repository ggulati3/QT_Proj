#ifndef SHOOTING_GAME_H
#define SHOOTING_GAME_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    int score=0;
    QTimer * timer = new QTimer();
    bool lost = false;

public slots:
    void spawn();
};

class shooting_game: public QGraphicsView
{
    Q_OBJECT
public:
    shooting_game();
    QGraphicsScene *scene;
    player* p = new player;
    void keyPressEvent(QKeyEvent* event);
    QGraphicsTextItem * scoreboard = new QGraphicsTextItem((QString("Score: ") + QString::number(p->score)));
    QTimer * timer = new QTimer(this);
    ~shooting_game();
public slots:
    void update_scoreboard();
signals:
    void won_game();
    void lose_game();
};

class bullet: public player
{
    Q_OBJECT
public:
    bullet(player* p);
    player* owner;
    QTimer * timer = new QTimer(this);
public slots:
    void move();
};

class enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy(player* play);
    player* p;
public slots:
    void move();
};

#endif // SHOOTING_GAME_H
