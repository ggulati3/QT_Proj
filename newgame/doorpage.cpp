#include "doorpage.h"

/* default constructor that creates a page with 3 instances of 'door' and 1 QPushButton
 */
doorPage::doorPage()
{


    layout->addWidget(d_1,0,0);
    layout->addWidget(d_2,0,1);
    layout->addWidget(d_3,0,2);
    layout->addWidget(button, 1, 0, 5, 1);
    //layout->addWidget(button_2, 1, 1, 5, 1);

    QObject::connect(button, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_1, SLOT(open_door()));
    QObject::connect(button_2, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_2, SLOT(open_door()));
    QObject::connect(button_3, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_3, SLOT(open_door()));

    this->setLayout(layout);
    this->show();
}

doorPage::~doorPage(){
    delete layout;
    delete button;
    delete button_2;
    delete button_3;
    delete d_1;
    delete d_2;
    delete d_3;
}
