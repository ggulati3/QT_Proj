#include "win_page_1.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QMovie>

/* constructor of win_page_1; called when a minigame is won
 * @param N/A
 * @return N/A
 * */
win_page_1::win_page_1()
{
    setStyleSheet("background-color:white;");
    QLabel* you_won = new QLabel("You did it! You earned another key");


    you_won->setStyleSheet("color: black");              //label color
    //you_won->setFixedSize(700, 100);
    QFont f("Cooper", 30, QFont::Bold);           //font type and size
    you_won->setFont(f);
    QVBoxLayout* layout = new QVBoxLayout;

    QLabel *lbl = new QLabel;
    QMovie *mv = new QMovie(":/key2.gif");
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);
    layout->addWidget(lbl);

    layout->addWidget(you_won);
    you_won->move(200, 50);
    layout->addWidget(win_game_button);
    setLayout(layout);
}
