#include "win_page_1.h"
#include <QLabel>
#include <QGridLayout>
#include <QPixmap>
#include <QMovie>

/* constructor of win_page_1; called when a minigame is won; adds a label, movie, and a back button
 * @param N/A
 * @return N/A
 * */
win_page_1::win_page_1()
{

    you_won->setStyleSheet("color: white");              //label color
    QFont f("Courier", 30, QFont::DemiBold);           //font type and size
    you_won->setFont(f);
    win_game_button->setFont(f);
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);
    layout->addWidget(lbl, 1,2);
    win_game_button->setFont(f);
    layout->addWidget(you_won, 1, 3);
    you_won->move(200, 50);
    layout->addWidget(win_game_button, 2, 3);
    setLayout(layout);
}
