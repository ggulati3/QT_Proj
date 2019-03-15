#include "key.h"

/* Constructor that creates a picture of a key
 * @param N/A
 * @return N/A
 */
key::key()
{
    QPixmap keypic(":/key.png");
    keypic = keypic.scaled(30,30);
    this->setPixmap(keypic);
}

/* Constructor that creates a widget containing one key
 * @param N/A
 * @return N/A
 */
keys::keys()
{
    layout->addWidget(key_1);
    setLayout(layout);
}
