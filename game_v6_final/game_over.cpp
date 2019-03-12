#include "game_over.h"
#include <QMovie>

#include<QHBoxLayout>

/* constructor for the game over page; creates a page with a gif
 * @param N/A
 * @return N/A
*/
game_over::game_over()
{
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);
    lbl->setFixedSize(900,400);
    lbl->setScaledContents(100);
    layout->addWidget(lbl);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);
}

/* destructor for the game over page
 * @param N/A
 * @return N/A
*/
game_over::~game_over(){
}
