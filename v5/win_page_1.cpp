#include "win_page_1.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

/* constructor of win_page_1; called when a minigame is won
 * @param N/A
 * @return N/A
 * */
win_page_1::win_page_1()
{
    setStyleSheet("background-color:white;");
    QLabel* you_won = new QLabel("You did it! You earned another key");
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(you_won);
    QPixmap pic(":/key.png");
    layout->addWidget(key_pic);
    layout->addWidget(win_game_button);
    setLayout(layout);
}
