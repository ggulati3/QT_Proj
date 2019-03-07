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

class gamethree: public QWidget
{
    Q_OBJECT
public:
    gamethree(); //default constructor- placeholder
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* win_game_button = new QPushButton("win");
    QGridLayout* layoutt = new QGridLayout;
    shooting_game* game = new shooting_game;
    int live = 3;
    ~gamethree();
public slots:
    void lose_life();

};



#endif // GAMETHREE_H
