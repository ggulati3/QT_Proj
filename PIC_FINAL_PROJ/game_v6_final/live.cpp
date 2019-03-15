#include "live.h"

/* Constructor that creates a picture of a heart
 * @param N/A
 * @return N/A
 */
live::live()
{
    QPixmap live1(":/lives.png");
    live1 = live1.scaled(40,15);
    this->setPixmap(live1);
}

/* Constructor that creates a widget containing three hearts
 * @param N/A
 * @return N/A
 */
lives::lives(){
    layoutt->addWidget(live_1);
    layoutt->addWidget(live_2);
    layoutt->addWidget(live_3);
    setLayout(layoutt);
}
