#include "spacerunner.h"
#include <QDebug>

spaceRunner::spaceRunner(QWidget * parent)
{
    setStyleSheet("background-color:black;");
    resize(500,500);

    hero_x = 200;
    hero_y = 200;
    hero = new QRect(hero_x,hero_y,100,100);

    block1_x = 0;
    block1_y = 10;
    block1 = new QRect(block1_x, block1_y, 200, 100);
    gameOver = false;


    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(moveBlock()));
    timer->start(1000); //time specified in ms
    QWidget::update();
    if(gameOver) {
        timer->stop();
    }

}

void spaceRunner::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    QPainter qp(this);
                // x, y , width, height
    qp.drawRect(hero_x,hero_y, 100, 100);

    qp.drawRect(block1_x,block1_y, 200, 100);

    if(hasBeenHit()) {
       // Game Over
       QString message = "Game over";
       QFont font("Courier", 15, QFont::DemiBold);
       QFontMetrics fm(font);
       int textWidth = fm.width(message);

       qp.setFont(font);
       int h = height();
       int w = width();

       qp.translate(QPoint(w/2, h/2));
       qp.drawText(-textWidth/2, 0, message);
       endGame();
    }

}


void spaceRunner::keyPressEvent(QKeyEvent *e) {
    int key = e->key();

    if(key == Qt::Key_Left) {
        if(hero_x > 0) {
            hero_x-=10;
        }
    }
    if(key == Qt::Key_Right){
        if(hero_x < 405)
            hero_x+=10;
    }
    if(key == Qt::Key_Up) {
        if(hero_y >0)
            hero_y-=10;
    }
    if(key == Qt::Key_Down) {
        if(hero_y<405)
            hero_y+=10;
    }

    QWidget::update();
    QWidget::keyPressEvent(e);
}



bool spaceRunner::hasBeenHit() {
    // current bug --> block hits from other side = no intersection
    if( hero_x >= block1_x && hero_x < block1_x+200 && hero_y >= block1_y && hero_y < block1_y+100) {
        return true;
    } else {
        return false;
    }
}

void spaceRunner::endGame() {
    hero_x = 1000;
    block1_x = 1000;
    gameOver = true;
    QWidget::update();
}

void spaceRunner::moveBlock() {
    block1_y+=40;
    QWidget::update();
}
