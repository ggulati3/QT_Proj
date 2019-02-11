#include "doorpage.h"

/* default constructor that creates a page with 3 instances of 'door' and 1 QPushButton
 */
doorPage::doorPage()
{
    QGridLayout* layout = new QGridLayout;

    layout->addWidget(d_1,0,0);
    layout->addWidget(d_2,0,1);
    layout->addWidget(d_3,0,2);
    layout->addWidget(button, 1, 0, 5, 1);

    QObject::connect(button, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_1, SLOT(open_door()));

    this->setLayout(layout);
    this->show();
}
