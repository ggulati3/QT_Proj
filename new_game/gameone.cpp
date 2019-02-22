#include "gameone.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>

/* constructor of game 1; this is a placeholder class for the first game
 * @param N/A
 * @return N/A
 * */
gameone::gameone()
{
    layoutt->addWidget(back_button);
    layoutt->addWidget(win_game_button);
    this->setLayout(layoutt);
}

/* destructor of game 1; this is a placeholder class for the first game
 * @param N/A
 * @return N/A
 * */
gameone::~gameone(){
    delete back_button;
    delete win_game_button;
    delete layoutt;
}
