#ifndef JUMPER
#define JUMPER

#include <QWidget>
#include <QKeyEvent>
#include <QImage>
#include <QTimer>

class Jumper : public QWidget {
    Q_OBJECT
    public:
       Jumper(QWidget *parent = 0);
    public slots:
       void move();
       void loadImages();
    protected:
       void paintEvent(QPaintEvent *);
       void keyPressEvent(QKeyEvent *);
    private:
       QImage hero;

       QRect * wall1;

       int hero_x;
       int hero_y;

       int wall_topL_x;
       int wall_topL_y;
       int wall_bottomR_x;
       int wall_bottomR_y;

       bool isOver;

       QTimer * timer;
       void initialDraw();

       bool hasHit();
};

#endif // JUMPER
