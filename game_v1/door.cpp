#include "door.h"
#include <QLabel>
#include <QPixmap>
#include <QPainter>

door::door(QWidget *parent)
{
    QPixmap pic(":/closedDoor.png");
    pic = pic.scaled(400,650);
    this->setPixmap(pic);
}


void door::open_door(){
   /*if(is_open){
       QPixmap pic(":/openDoor.png");
       pic = pic.scaled(100,200);
       this->setPixmap(pic);
   }
   else{

       QPixmap pic(":/closedDoor.png");
       pic = pic.scaled(100,200);
       this->setPixmap(pic);
   } */

    QPixmap pic(":/openDoor.png");
    pic = pic.scaled(400,650);
    this->setPixmap(pic);
}
