#include "game_one.h"
#include <QLabel>
#include <QHBoxLayout>
game_one::game_one()
{
    QLabel* label = new QLabel("hello");
    QHBoxLayout* layoutt = new QHBoxLayout;
    layoutt->addWidget(label);
    this->setLayout(layoutt);
}
