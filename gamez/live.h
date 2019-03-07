#ifndef LIVE_H
#define LIVE_H

#include <QLabel>
#include <QHBoxLayout>
class live: public QLabel
{
public:
    live();
};

class lives: public QWidget
{
public:
    lives();
    live live_1;
    live live_2;
    live live_3;
    QHBoxLayout* layoutt = new QHBoxLayout;

};
#endif // LIVE_H
