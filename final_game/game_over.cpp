#include "game_over.h"
#include <QMovie>

#include<QHBoxLayout>
game_over::game_over()
{
    QLabel* lbl = new QLabel;
    QMovie* mv = new QMovie(":/game_over.gif");
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(lbl);
    setLayout(layout);
}
