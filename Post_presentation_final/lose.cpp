#include "lose.h"
#include <QMovie>
#include <QStackedWidget>

/* Constructor that creates a lose page - with a label and 2 buttons
 * @param N/A
 * @return N/A
 */
lose::lose()
{
    this->setStyleSheet("color:black");
    QFont f("Courier", 15, QFont::DemiBold);

    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    picture->setPixmap(pic);

    try_again->setFixedSize(200,100);
    try_again->setFont(f);

    back_button->setFixedSize(200,100);
    back_button->setFont(f);

    layoutt->addWidget(back_button,4,1);
    layoutt->addWidget(try_again,4,2);
    layoutt->addWidget(picture,3,1);

    this->setFixedSize(700, 600);
    this->setLayout(layoutt);
}

