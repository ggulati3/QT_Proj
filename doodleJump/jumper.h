#ifndef JUMPER
#define JUMPER

#include <QWidget>
#include <QKeyEvent>
#include <QImage>

class Jumper : public QWidget {
    public:
       Jumper(QWidget *parent = 0);
    protected:
       void paintEvent(QPaintEvent *);
//       void timerEvent(QTimerEvent *);
       void keyPressEvent(QKeyEvent *);
    private:
       QImage hero;
       QImage ball;

       int hero_x;
       int hero_y;

       int ball_x;
       int ball_y;

       int x[500];
       int y[500];

       bool moveLeft;
       bool moveRight;
       bool moveUp;
       bool moveDown;

       void loadImages();
       void initialDraw();
};

#endif // JUMPER
