#ifndef GAMETHREE_H
#define GAMETHREE_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QKeyEvent>
#include "spacerunner.h"

class gamethree: public QWidget
{
public:
    gamethree(); //default constructor- placeholder
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* win_game_button = new QPushButton("win game !!!!");
    QHBoxLayout* layoutt = new QHBoxLayout;
    ~gamethree();
};

#endif // GAMETHREE_H
