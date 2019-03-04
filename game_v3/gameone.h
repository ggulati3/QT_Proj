#ifndef GAMEONE_H
#define GAMEONE_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QKeyEvent>
class gameone: public QWidget
{
public:
    gameone(); //default constructor- placeholder
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* win_game_button = new QPushButton("win game -> advance to next stage");
    QGridLayout* layoutt = new QGridLayout;
    ~gameone();

};

#endif // GAMEONE_H
