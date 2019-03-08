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
    lbl->setFixedSize(900,400);
    lbl->setScaledContents(100);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(lbl);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);
}
