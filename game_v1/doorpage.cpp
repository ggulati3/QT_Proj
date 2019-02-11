#include "doorpage.h"

doorPage::doorPage()
{

    QGridLayout* layout = new QGridLayout;

    layout->addWidget(d_1,0,0);
    layout->addWidget(d_2,0,1);
    layout->addWidget(d_3,0,2);


    QObject::connect(button, SIGNAL(clicked()),
    d_1, SLOT(open_door()));

    layout->addWidget(button, 1, 0, 5, 1);

    this->setLayout(layout);
    this->show();
}
