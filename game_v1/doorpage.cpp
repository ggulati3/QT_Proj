#include "doorpage.h"

doorPage::doorPage()
{

    QGridLayout* layout = new QGridLayout;

    door* d_1 = new door;
    door* d_2 = new door;
    door* d_3 = new door;

    layout->addWidget(d_1,0,0);
    layout->addWidget(d_2,0,1);
    layout->addWidget(d_3,0,2);

    QPushButton* button = new QPushButton("Enter");
    layout->addWidget(button, 1, 0);

    this->setLayout(layout);
    this->show();
}
