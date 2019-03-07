#include "spacerunner.h"
#include <QDebug>

/*
 Initialize spaceRunner W/ no params (includes setting basic view and creating connection for yellow dots to move)
 @param: N/A
 @return: N/A
 */

spaceRunner::spaceRunner(QWidget * parent)
{
    setStyleSheet("background-color:white;");


    hero_x = 160;
    hero_y = 610;
    hero = new QRect(hero_x,hero_y,100,100);

    border_x = 0;
    border_y = 10;
    border = new QRect(border_x, border_y, 200, 100);
    gameOver = false;

    for(int i = 1; i < 6; i++) {
        yellowDots.push_back(new YellowDot(30, (i*100)+50));
    }
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveBlock()));
    timer->start(500); //time specified in ms
    QWidget::update();
//    if(hasWon || gameOver) {
//        if(gameOver) {
//            resetGame();
//            QWidget::update();
//        }
//        //timer->stop();
//    }

}

/*
 paintEvent -- draw rectangles and dots on screen
 @param: QPaintEvent * e -- used to draw items on screem
 @return: N/A
 */

void spaceRunner::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
    QColor red("#ff0000");
    QBrush brush(red, Qt::SolidPattern);
    qp.drawRect(30,100,300,550);

    qp.setBrush(QColor("#89cff0"));
    qp.drawRect(30,610,300, 40);
    qp.drawRect(30,100,300, 40);

    qp.setBrush(Qt::red);
    qp.drawEllipse(hero_x,hero_y, 30,30);

    qp.setBrush(QColor("#ffff00"));
    // loop through yellowDot vector and draw them on the screen in vertical line
    for(int i = 0; i < yellowDots.size(); i++) {
        qp.drawEllipse(yellowDots[i]->getX(), yellowDots[i]->getY(), 30,30);
    }

    // Check if hero has got to finish line -- then show user that he/she has won
    if(hasWon) {
       QFont font("Courier", 60, QFont::DemiBold);
       qp.setPen("white");
       qp.setFont(font);
       qp.drawText(QPoint(50,450), "YOU WON");
    }

    if(gameOver) {
        QFont font("Courier", 60, QFont::DemiBold);
        qp.setPen("white");
        qp.setFont(font);
        qp.drawText(QPoint(50,450), "YOU LOST");
        emit endGame();
        gameOver= false;
        resetGame();
    }



}

/*
 Move the hero right by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_right() {
    if(hero_x < 300 && !hasWon && !gameOver) {
        hero_x+=10;
        hasBeenHit();
    }
    //qDebug() << "(" << hero_x << ", " << hero_y << ")";
}

/*
 Move the hero left by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_left() {
    if(hero_x > 30 && !hasWon && !gameOver) {
        hero_x-=10;
        hasBeenHit();
    }
     //qDebug() << "(" << hero_x << ", " << hero_y << ")";
}

/*
 Move the hero up by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_up() {
    if(hero_y > 100 && !hasWon && !gameOver) {
        hero_y-=10;
        hasBeenHit();
    }
    if(hero_y == 120) {
        hasWon = true;
    }
    //qDebug() << "(" << hero_x << ", " << hero_y << ")";
    //qDebug() << hasWon;
}

/*
 Move the hero down by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_down() {
    if(hero_y < 620 && !hasWon && !gameOver) {
        hero_y+=10;
        hasBeenHit();
    }
    //qDebug() << "(" << hero_x << ", " << hero_y << ")";
}

/*
 Move the yellow dots right or left depending on their location on the screen (the dots oscillate left to right)
 @param: N/A
 @return: N/A
 */

void spaceRunner::moveBlock() {
    for(int i = 0; i < yellowDots.size(); i++) {
        if(goRight) {
            yellowDots[i]->move_right();
            if(yellowDots[i]->getX() > 290) {
               goRight = false;
            }
        } else {
            yellowDots[i]->move_left();
            if(yellowDots[i]->getX() == 30) {
                goRight = true;
            }
        }
     }
    hasBeenHit();
    if(gameOver) {
        resetGame();
    }
    if(!hasWon && !gameOver)
     QWidget::update();

}

void spaceRunner::hasBeenHit() {
    for(int i = 0 ; i < yellowDots.size(); i++) {
        if(hero_x <= yellowDots[i]->getX()+25 && hero_x >= yellowDots[i]->getX() -25 && hero_y <= yellowDots[i]->getY()+25 && hero_y >= yellowDots[i]->getY() -25){ // +-15
            qDebug() << "INTERSECTION";
            gameOver = true;
        }
    }

}

void spaceRunner::resetGame(){
    hero_x = 160;
    hero_y = 610;
    for(int i = 0; i< yellowDots.size(); i++) {
        yellowDots[i]->resetCoord();
    }
}

/*-------------------------Yello Dot ------------------*/

/*
 Defualt Constructor for YelloDot -- set coord at (0,0)
 @param: N/A
 @return: N/A
 */

YellowDot::YellowDot() : x(0), y(0) {}
/*
 Constructor with parameters for Yellow Dot -- set coord based off user input
 @param: int x_coord, int y_coor -- coordinates for dot
 @return: N/A
 */

YellowDot::YellowDot(int x_coord, int y_coord)
    : x(x_coord), y(y_coord) {}

/*
 Move the yello dot left by 20 px
 @param: N/A
 @return: N/A
 */
void YellowDot::move_left() {
    x-=20;
}
/*
 Move the yello dot right by 20 px
 @param: N/A
 @return: N/A
 */
void YellowDot::move_right() {
    x+=20;
}
/*
 get the value of the dot x_coord
 @param: N/A
 @return: int x -- the x coord
 */
int YellowDot::getX(){
    return x;
}
/*
 get the value of the dot y_coord
 @param: N/A
 @return: int y -- the y coord
 */
int YellowDot::getY(){
    return y;
}

void YellowDot::resetCoord() {
    x = 30;
}
