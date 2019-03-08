#ifndef GAMEONE_H
#define GAMEONE_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QKeyEvent>
#include <QTimer>
#include <QPainter>
#include <QLabel>
#include "spacerunner.h"

class gameone: public QWidget
{
    Q_OBJECT
public:
    gameone(); //default constructor- placeholder
    QPushButton* back_button = new QPushButton("back to main screen");
    QPushButton* win_game_button = new QPushButton("win game -> advance to next stage");
    QGridLayout* layoutt = new QGridLayout;
    spaceRunner *game = new spaceRunner(this);
    ~gameone();
protected:
    void keyPressEvent(QKeyEvent *);
};

#endif // GAMEONE_H
