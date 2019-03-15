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
    border = new QRect(border_x, border_y, 220, 100);
    gameOver = false;
    // add 6 yellow dots to the yellowDot vector
    for(int i = 1; i < 6; i++) {
        yellowDots.push_back(new YellowDot(30, (i*100)+50));
        goRightVect.push_back(true);
    }
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveBlock()));
    timer->start(50); //time specified in ms
    QWidget::update();

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
    for(size_t i = 0; i < yellowDots.size(); i++) {
        qp.drawEllipse(yellowDots[i]->getX(), yellowDots[i]->getY(), 30,30);
    }

    // Check if hero has got to finish line -- then show user that he/she has won
    if(hasWon) {
       QFont font("Courier", 60, QFont::DemiBold);
       qp.setPen("white");
       qp.setFont(font);
       qp.drawText(QPoint(50,450), "YOU WON");
       emit winGame();
    }
    // Check if game is over -- alert the user that they lost and set the flag gameOver to false/
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
    // if the player is within bounds and no flags have been changed, let the user move right
    if(hero_x < 300 && !hasWon && !gameOver) {
        hero_x+=12;
        hasBeenHit();
    }
}

/*
 Move the hero left by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_left() {
    // if the player is within bounds and no flags have been changed, let the user move left
    if(hero_x > 30 && !hasWon && !gameOver) {
        hero_x-=12;
        hasBeenHit();
    }
}

/*
 Move the hero up by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_up() {
    // if the player is within bounds and no flags have been changed, let the user move i[
    if(hero_y > 100 && !hasWon && !gameOver) {
        hero_y-=12;
        hasBeenHit();
    }
    // if the player reaches the other blue rectange, change the hasWon flag to true
    if(hero_y <= 118) {
        hasWon = true;
    }
}

/*
 Move the hero down by 10 px
 @param: N/A
 @return: N/A
 */

void spaceRunner::move_hero_down() {
    // if the player is within bounds and no flags have been changed, let the user move down
    if(hero_y < 620 && !hasWon && !gameOver) {
        hero_y+=12;
        hasBeenHit();
    }
}

/*
 Move the yellow dots right or left depending on their location on the screen (the dots oscillate left to right)
 @param: N/A
 @return: N/A
 */

void spaceRunner::moveBlock() {
    // iterate through the vector of yellow dots to move each yellow dot.
    for(size_t i = 0; i < yellowDots.size(); i++) {
        //check to see if yellow dots are in range to go right (if not go to else statement where yellow dots move left)
        if(goRightVect[i]) {
            // check to see if we need to change the flag so yellow dot moves left
            if(yellowDots[i]->getX() >= 290) {
                goRightVect[i] = false;
            }
             yellowDots[i]->move_right();
        } else {
            // check to see if we need to change the flag so yellow dot moves right
            if(yellowDots[i]->getX() <= 40) {
                goRightVect[i] = true;
            }
             yellowDots[i]->move_left();
        }
     }
    hasBeenHit();
    // if gameOver flag has been alerted, reset game to initail positions
    if(gameOver) {
        resetGame();
        QWidget::update();
    }
    // update the game scene if either flag has changed
    if(!hasWon && !gameOver)
     QWidget::update();

}

/*
 Check to see if the hero intersects with any of the yellow dots
 @param: N/A
 @return: N/A
 */
void spaceRunner::hasBeenHit() {
    // iterate through the yellow Dot Vector to get their coordinates
    for(size_t i = 0 ; i < yellowDots.size(); i++) {
        // check to see if the yellow dot intersects with the hero via coordinate math
        if(hero_x <= yellowDots[i]->getX()+25 && hero_x >= yellowDots[i]->getX() -25 && hero_y <= yellowDots[i]->getY()+25 && hero_y >= yellowDots[i]->getY() -25){ // +-15
            gameOver = true;
        }
    }

}
/*
 reset game by putting all items (the hero and yellow dots) in their starting place.
 @param: N/A
 @return: N/A
 */
void spaceRunner::resetGame(){
    hero_x = 160;
    hero_y = 610;
    for(size_t i = 0; i< yellowDots.size(); i++) {
        yellowDots[i]->resetCoord();
        goRightVect[i] = true;
    }
}

/*-------------------------Yellow Dot ------------------*/

/*
 Defualt Constructor for YellowDot -- set coord at (0,0)
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
    x-=10;
}
/*
 Move the yello dot right by 20 px
 @param: N/A
 @return: N/A
 */
void YellowDot::move_right() {
    x+=10;
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
/*
 reset the yellow dot to its inital x coord
 @param: N/A
 @return: N/A
 */
void YellowDot::resetCoord() {
    x = 20;
}
