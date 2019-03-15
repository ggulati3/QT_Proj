#ifndef LIVE_H
#define LIVE_H

#include <QLabel>
#include <QHBoxLayout>

/* class that contains a label with a picture of a live
 */
class live: public QLabel
{
public:
    live();
};

/* class that contains 3 instances of a live, and a horizontal layout
 * */
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
