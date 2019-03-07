#include "live.h"

live::live()
{
    QPixmap live1(":/lives.png");
    live1 = live1.scaled(40,15);
    this->setPixmap(live1);
}

lives::lives(){
    layoutt->addWidget(live_1);
    layoutt->addWidget(live_2);
    layoutt->addWidget(live_3);
    setLayout(layoutt);
}
