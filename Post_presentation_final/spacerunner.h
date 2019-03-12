#ifndef SPACERUNNER_H
#define SPACERUNNER_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QPushButton>
#include <QGridLayout>
#include <vector>

class YellowDot : public QWidget {
public:
    YellowDot();
    YellowDot(int x_coord, int y_coord);
    void move_right();
    void move_left();
    int getX();
    int getY();
    void resetCoord();

private:
    int x;
    int y;
};


class spaceRunner : public QWidget
{
    Q_OBJECT
public:
    spaceRunner(QWidget *parent);
    void move_hero_right();
    void move_hero_left();
    void move_hero_down();
    void move_hero_up();
    void resetGame();
    bool hasWon = false;
    bool gameOver = false;
protected:
    void paintEvent(QPaintEvent *e);
public slots:
    void moveBlock();
signals:
    void endGame();
    void winGame();
private:

   QRect * hero;
   int hero_x;
   int hero_y;

   QRect * border;
   int border_x;
   int border_y;

   void hasBeenHit();
   std::vector<bool> goRightVect;

   QTimer * timer;

   std::vector<YellowDot*> yellowDots;


};


#endif // SPACERUNNER_H
