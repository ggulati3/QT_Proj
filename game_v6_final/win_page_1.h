#ifndef WIN_PAGE_1_H
#define WIN_PAGE_1_H
#include <key.h>
#include <QWidget>
#include <QPushButton>
#include <QMovie>
class win_page_1: public QWidget
{
public:
    win_page_1();
    QPushButton* win_game_button = new QPushButton("back to main screen");
    QLabel *lbl = new QLabel;
    QMovie *mv = new QMovie(":/key2.gif");
    QGridLayout* layout = new QGridLayout;
    QLabel* you_won = new QLabel("You did it! You earned another key");
};

#endif // WIN_PAGE_1_H
