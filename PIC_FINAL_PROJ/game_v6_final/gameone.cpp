#include "gameone.h"
#include <QDebug>
/* constructor of game 1; adds buttons (for layout), game,  and sets layout
 * @param N/A
 * @return N/A
 * */
gameone::gameone()
{
    setFocusPolicy(Qt::StrongFocus);
    layoutt->addWidget(game, 4, 4);
    layoutt->addWidget(back_button,10,0);
    layoutt->addWidget(win_game_button,10,10);
    back_button->setStyleSheet("QPushButton{background:transparent;}");
    win_game_button->setStyleSheet("QPushButton{background:transparent;}");


     this->setLayout(layoutt);
}

/* destructor of game 1
 * @param N/A
 * @return N/A
 * */
gameone::~gameone(){
}

/*
 move the hero based of the arrow keys
 @param: QKeyEvent * e -- the pointer that shows what the user pressed
 @return: N/A
 */
void gameone::keyPressEvent(QKeyEvent *e){
    int key = e->key();

    if(key == Qt::Key_Right) {      //if right key pressed, move hero right
        game->move_hero_right();

    }
    if(key == Qt::Key_Left) {       //if left key pressed, move hero left
        game->move_hero_left();

    }
    if(key == Qt::Key_Down) {       //if down arrow key pressed, move hero down
        game->move_hero_down();

    }
    if(key == Qt::Key_Up) {         //if up arrow key pressed, move hero up
        game->move_hero_up();

    }

    QWidget::update();
}
