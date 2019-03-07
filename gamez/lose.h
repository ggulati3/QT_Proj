#ifndef LOSE_H
#define LOSE_H
#include <QLabel>
#include <QPushButton>
#include <QLayout>
class lose: public QLabel
{
public:
    lose();
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* try_again = new QPushButton("try again");
    QVBoxLayout* layoutt = new QVBoxLayout;
};

#endif // LOSE_H
