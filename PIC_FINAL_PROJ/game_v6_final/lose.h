#ifndef LOSE_H
#define LOSE_H
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QStackedWidget>
#include <QObject>

/* class for a standard 'you lose' page; containing a 'you lose' label, try again button, and a back button
 * */
class lose: public QLabel
{
public:
    lose();
    QPushButton* back_button = new QPushButton("back to \nmain screen");
    QPushButton* try_again = new QPushButton("try again");
    QGridLayout* layoutt = new QGridLayout;
    QLabel* picture = new QLabel;
};


#endif // LOSE_H
