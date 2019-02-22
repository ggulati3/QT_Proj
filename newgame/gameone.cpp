#include "gameone.h"
#include <QLabel>
#include <QLayout>
#include <QPushButton>
gameone::gameone()
{
    layoutt->addWidget(back_button);
    layoutt->addWidget(win_game_button);
    this->setLayout(layoutt);
}

gameone::~gameone(){
    delete back_button;
    delete win_game_button;
    delete layoutt;
}
