#include "gameone.h"
#include <QDebug>
/* constructor of game 1; this is a placeholder class for the first game
 * @param N/A
 * @return N/A
 * */
gameone::gameone()
{
    setFocusPolicy(Qt::StrongFocus);

     layoutt->addWidget(game,4,4);
     layoutt->addWidget(back_button,10,0);
     back_button->setStyleSheet("QPushButton{background:transparent;}");
     win_game_button->setStyleSheet("QPushButton{background:transparent;}");
     layoutt->addWidget(win_game_button,10,10);

     this->setLayout(layoutt);
}

/* destructor of game 1; this is a placeholder class for the first game
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

    if(key == Qt::Key_Right) {
        game->move_hero_right();

    }
    if(key == Qt::Key_Left) {
        game->move_hero_left();

    }
    if(key == Qt::Key_Down) {
        game->move_hero_down();

    }
    if(key == Qt::Key_Up) {
        game->move_hero_up();

    }

    QWidget::update();
}
