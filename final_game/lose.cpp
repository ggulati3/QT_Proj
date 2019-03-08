#include "lose.h"
#include <QMovie>
#include <QStackedWidget>
lose::lose()
{
    this->setStyleSheet("background-color:black;");
    QLabel* picture = new QLabel;
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    picture->setPixmap(pic);
    QVBoxLayout* vert = new QVBoxLayout;
    QWidget* buttons = new QWidget;
    lbl = new QLabel;
    mv = new QMovie(":/loading.gif");
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);
    lbl->setFixedSize(200, 200);
    try_again->setFixedSize(200,100);
    back_button->setFixedSize(200,100);
    stack->addWidget(try_again);//index 0
    stack->addWidget(lbl);//index 1
    stack->setCurrentIndex(0);
    stack->setFixedSize(200, 200);
    this->setFixedSize(700, 600);
    vert->addWidget(back_button);
    vert->addWidget(stack);
    buttons->setLayout(vert);
    layoutt->addWidget(buttons,4,7);
    layoutt->addWidget(picture,4,5);
    layoutt->setAlignment(buttons, Qt::AlignHCenter);
    this->setStyleSheet("color:black");
    this->setLayout(layoutt);


}

gameonelose::gameonelose()
{
    this->setStyleSheet("background-color:black;");
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    this->setPixmap(pic);
    layoutt->addWidget(back_button);
    layoutt->addWidget(try_again);
    setLayout(layoutt);
}

gametwolose::gametwolose()
{
    this->setStyleSheet("background-color:black;");
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    this->setPixmap(pic);
    layoutt->addWidget(back_button);
    layoutt->addWidget(try_again);
    setLayout(layoutt);
}
