#ifndef GAMETWO_H
#define GAMETWO_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
class gametwo: public QWidget
{
public:
    gametwo(); //default constructor- placeholder
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* win_game_button = new QPushButton("win game -> advance to next stage");
    QHBoxLayout* layoutt = new QHBoxLayout;
    ~gametwo();
};

#endif // GAMETWO_H