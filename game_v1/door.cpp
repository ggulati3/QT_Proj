#include "door.h"
#include <QLabel>
#include <QPixmap>

door::door(QWidget *parent)
{
    QPixmap pic("/Users/gauravgulati/desktop/game_v1/closedDoor.png"); // need to change so dynamic -- maybe AWS s3 bucket link?
    pic = pic.scaled(100,200);
    this->setPixmap(pic);
}
