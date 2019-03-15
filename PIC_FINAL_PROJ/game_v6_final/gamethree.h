#ifndef GAMETHREE_H
#define GAMETHREE_H
#include "shooting_game.h"
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QLabel>
#include <QFont>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsPixmapItem>

/* class that contains game three; two buttons, layout, and game-an instance of shooting_game
 *
 * */
class gamethree: public QWidget
{
    Q_OBJECT
public:
    gamethree();
    QPushButton* back_button = new QPushButton();
    QPushButton* win_game_button = new QPushButton();
    QGridLayout* layoutt = new QGridLayout;
    shooting_game* game = new shooting_game;
    ~gamethree();
};



#endif // GAMETHREE_H
