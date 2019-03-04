#ifndef SPACERUNNER_H
#define SPACERUNNER_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
class spaceRunner : public QWidget
{
    Q_OBJECT
public:
    spaceRunner(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
public slots:
    void moveBlock();
private:
   QRect * hero;
   int hero_x;
   int hero_y;

   QRect * block1;
   int block1_x;
   int block1_y;


   bool hasBeenHit();
   bool gameOver;
   void endGame();

   QTimer * timer;

};

#endif // SPACERUNNER_H
