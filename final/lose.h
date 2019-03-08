#ifndef LOSE_H
#define LOSE_H
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QStackedWidget>
#include <QObject>
class lose: public QLabel
{
public:
    lose();
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* try_again = new QPushButton("try again");
    QGridLayout* layoutt = new QGridLayout;
    QStackedWidget* stack = new QStackedWidget;
    QLabel *lbl;
    QMovie *mv;
};

class gameonelose: public QLabel
{
public:
    gameonelose();
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* try_again = new QPushButton("try again");
    QGridLayout* layoutt = new QGridLayout;
};

class gametwolose: public QLabel
{
public:
    gametwolose();
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* try_again = new QPushButton("try again");
    QGridLayout* layoutt = new QGridLayout;
};


#endif // LOSE_H
