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
    live* live_1 = new live;
    live* live_2 = new live;
    live* live_3 = new live;
    QHBoxLayout* layoutt = new QHBoxLayout;

};
#endif // LIVE_H
