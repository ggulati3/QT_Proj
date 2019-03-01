#include <QPainter>
#include <QTime>
#include <QDebug>
#include "jumper.h"

Jumper::Jumper(QWidget *parent) : QWidget (parent) {
    setStyleSheet("background-color:black;");
    resize(500,500);

    hero_x = 100;
    hero_y = 375;

    loadImages();
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
        if(hero_x < 405)
            hero_x+=10;
        QWidget::update();
        qDebug() << hero_x;
    }
    if(key == Qt::Key_Up) {
        if(hero_y >0)
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

    QImage importBall("/Users/gauravgulati/desktop/dot.png");
    ball = importBall.scaled(30,30, Qt::KeepAspectRatio);
}

void Jumper::initialDraw() {
    QPainter qp(this);

    qp.drawImage(hero_x, hero_y, hero);
    qp.drawImage(100,0, ball);
}


