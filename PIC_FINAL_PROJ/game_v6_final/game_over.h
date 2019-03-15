#ifndef GAME_OVER_H
#define GAME_OVER_H
#include <QWidget>
#include <QLabel>
#include <QMovie>
#include <QHBoxLayout>

/* class of a page with with a game over gif; page for when you lose all three lives
 * */
class game_over: public QLabel
{
public:
    game_over();
    QLabel* lbl = new QLabel;
    QMovie* mv = new QMovie(":/game_over.gif");
    QHBoxLayout* layout = new QHBoxLayout;
    ~game_over();
};

#endif // GAME_OVER_H
