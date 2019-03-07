#include "finalpage.h"
#include "QPixmap"

/* default constructor, placeholder trophy image
 * @param N/A
 * @return N/A
 * */
finalpage::finalpage()
{
    QPixmap pic(":/pixel.png");
    pic = pic.scaled(200,300);
    this->setPixmap(pic);

}
