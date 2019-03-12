#include "gamethree.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QFont>

/* constructor of game 3
 * @param N/A
 * @return N/A
 * */
gamethree::gamethree()
{
    setFocusPolicy(Qt::StrongFocus);
    layoutt->addWidget(game,4,4);
    layoutt->addWidget(back_button,10,0);
    back_button->setStyleSheet("QPushButton{background:transparent;}");
    win_game_button->setStyleSheet("QPushButton{background:transparent;}");
    layoutt->addWidget(win_game_button,10,10);
    this->setLayout(layoutt);
}


/* destructor of game 3
 * @param N/A
 * @return N/A
 * */
gamethree::~gamethree(){
}


