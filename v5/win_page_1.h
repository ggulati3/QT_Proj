#ifndef WIN_PAGE_1_H
#define WIN_PAGE_1_H
#include <key.h>
#include <QWidget>
#include <QPushButton>
class win_page_1: public QWidget
{
public:
    win_page_1();
    key * key_pic = new key;
    QPushButton* win_game_button = new QPushButton("back to main screen");
};

#endif // WIN_PAGE_1_H
