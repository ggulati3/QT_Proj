#include "game_over.h"

game_over::game_over()
{
    setStyleSheet("background-color:white;");
    QPixmap pic(":/game_over.png");
    pic = pic.scaled(400,200);
    this->setPixmap(pic);
}
