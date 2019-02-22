#include "key.h"

/* Constructor that creates a picture of a key
 * @param N/A
 * @return N/A
 */
key::key()
{
    QPixmap keypic(":/key.png");
    keypic = keypic.scaled(25,25);
    this->setPixmap(keypic);
}
