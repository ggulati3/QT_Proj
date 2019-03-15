#include "door.h"
#include <QLabel>
#include <QPixmap>
#include <QPainter>

/* Constructor that creates a picture of a closed door
 * @param N/A
 * @return N/A
 */
door::door()
{
    QPixmap pic(":/closedDoor.png");
    pic = pic.scaled(400,650);
    this->setPixmap(pic);
    this->setLayout(door_lay);
}


/* Function that replaces closed door image with open door image
 * @param N/A
 * @return N/A
 */
void door::open_door(){
    QPixmap pic(":/openDoor.png");
    pic = pic.scaled(400,650);
    this->setPixmap(pic);
}
