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
    layoutt->addWidget(win_game_button,10,10);
    this->setLayout(layoutt);

}

void gamethree::lose_life(){
    live--;

    if(live==2){
        layoutt->removeWidget(game);
        layoutt->addWidget(game_2,4,4);
    }
    if(live==1){
        layoutt->removeWidget(game_2);
        layoutt->addWidget(game_3,4,4);
    }
}

/* destructor of game 3
 * @param N/A
 * @return N/A
 * */
gamethree::~gamethree(){
}


