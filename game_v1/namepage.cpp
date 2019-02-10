#include "namepage.h"

NamePage::NamePage()
{
    QHBoxLayout* layout = new QHBoxLayout;
    QPushButton* enterButton = new QPushButton("ENTER");

    layout->addWidget(enterButton);

    this->setLayout(layout);
//    this->show();

}
