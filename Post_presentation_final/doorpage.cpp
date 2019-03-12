#include "doorpage.h"

/* default constructor that creates a page with 3 instances of 'door' and 1 QPushButton
 * @param N/A
 * @return N/A
 */
doorPage::doorPage()
{   layout->addWidget(d_1,0,0);
    layout->addWidget(d_2,0,1);
    layout->addWidget(d_3,0,2);

    (d_1->door_lay)->addWidget(button);

    const QSize b_size = QSize(400, 500);
    button->setFixedSize(b_size);
    button_2->setFixedSize(b_size);
    button_3->setFixedSize(b_size);

    button->setStyleSheet("QPushButton{background:transparent;}");
    button_2->setStyleSheet("QPushButton{background:transparent;}");
    button_3->setStyleSheet("QPushButton{background:transparent;}");

    QObject::connect(button, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_1, SLOT(open_door()));
    QObject::connect(button_2, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_2, SLOT(open_door()));
    QObject::connect(button_3, SIGNAL(clicked()), //clicking the enter button->opening the door
    d_3, SLOT(open_door()));

    this->setLayout(layout);
    this->show();
}

/* destructor for doorPage
 * @param N/A
 * @return N/A
 * */
doorPage::~doorPage(){
}
