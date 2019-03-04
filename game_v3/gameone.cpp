#include "gameone.h"
#include "spacerunner.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>

/* constructor of game 1; this is a placeholder class for the first game
 * @param N/A
 * @return N/A
 * */
gameone::gameone()
{
    layoutt->addWidget(back_button,0,0);
    layoutt->addWidget(win_game_button,0,2);
    this->setLayout(layoutt);

    QWidget* game = new spaceRunner;
    QGridLayout* l1 = new QGridLayout;
    game->setStyleSheet("background-color:black;");
    layoutt->addWidget(game,1,1);
    game->setFixedSize(600,600);
    game->setLayout(l1);



}

/* destructor of game 1; this is a placeholder class for the first game
 * @param N/A
 * @return N/A
 * */
gameone::~gameone(){
}
