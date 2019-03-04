#include <QPainter>
#include <QDebug>
#include "jumper.h"

Jumper::Jumper(QWidget *parent) : QWidget (parent) {
    setStyleSheet("background-color:black;");
    resize(500,500);

    hero_x = 100;
    hero_y = 375;

    loadImages();


    timer = new QTimer(this);
    //timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000);

}

void Jumper::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);

    initialDraw();
}


void Jumper::keyPressEvent(QKeyEvent *e) {
    int key = e->key();

    if(key == Qt::Key_Left) {
        if(hero_x > 0)
            hero_x-=10;
        QWidget::update();
        qDebug() << hero_x;
    }
    if(key == Qt::Key_Right){
        if(hero_x < 415)
            hero_x+=10;
        QWidget::update();
        qDebug() << hero_x;
    }
    if(key == Qt::Key_Up) {
        if(hero_y > -10)
            hero_y-=10;
        QWidget::update();
        qDebug() << hero_y;
    }
    if(key == Qt::Key_Down) {
        if(hero_y<405)
            hero_y+=10;
        QWidget::update();
        qDebug() << hero_y;
    }

    QWidget::keyPressEvent(e);
}

void Jumper::loadImages() {
    QImage importHero("/Users/gauravgulati/desktop/head.png");
    hero = importHero.scaled(60,60, Qt::KeepAspectRatio);

    wall_topL_x = 0;
    wall_topL_y = 0;
    wall_bottomR_x = 100;
    wall_bottomR_y = 100;
    wall1 = new QRect(wall_topL_y,wall_bottomR_y,200,100);

}

void Jumper::initialDraw() {
    QPainter qp(this);

    qp.drawImage(hero_x, hero_y, hero);
    qp.drawRect(*wall1);


}

void Jumper::move() {
    wall_topL_y-=30;
    wall_bottomR_y-=30;
    QWidget::update();
}

bool Jumper::hasHit() {

}
