#ifndef SHOOTING_GAME_H
#define SHOOTING_GAME_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>

/* class that contains a score, timer, a bool lost set to false since the game initializes as not lost yet,
 * and delete_enemies set to false since enemies are deleted only when lost=true; player class also contains a public slot spawn to create enemies
 * */
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    player();
    int score=0;
    QTimer * timer = new QTimer();
    bool lost = false;
    bool delete_enemies = false;

public slots:
    void spawn();
};

/* class that contains a scene, a player, scoreboard, timer, font. Also has keyPressEvent function for user interaction,
 *  public slot to update the scoreboard, and signals for game lost or won
 * */
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
    QFont* f= new QFont("Courier", 30, QFont::DemiBold);
    ~shooting_game();
public slots:
    void update_scoreboard();
signals:
    void won_game();
    void lose_game();
};

/* class that contains a player as an owner of this bullet, a timer, and a public slot to move the bullet
 * */
class bullet: public player
{
    Q_OBJECT
public:
    bullet(player* p);
    player* owner;
    QTimer * bullet_timer = new QTimer(this);
    //~bullet();
public slots:
    void move();
};

/* class that contains a player as an owner of this enemy, and a public slot to move the enemy
 * */
class enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    enemy(player* play);
    player* player1;
public slots:
    void move();
};

#endif // SHOOTING_GAME_H
