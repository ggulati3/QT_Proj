#include "lose.h"

lose::lose()
{
    setStyleSheet("background-color:white;");
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    this->setPixmap(pic);
    layoutt->addWidget(back_button);
    layoutt->addWidget(try_again);
    setLayout(layoutt);
}
