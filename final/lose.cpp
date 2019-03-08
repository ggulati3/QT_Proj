#include "lose.h"
#include <QMovie>
#include <QStackedWidget>
lose::lose()
{
    this->setStyleSheet("background-color:black;");
    QLabel* picture = new QLabel;
    QFont f("Courier", 15, QFont::DemiBold);
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    picture->setPixmap(pic);
    QVBoxLayout* vert = new QVBoxLayout;
    QWidget* buttons = new QWidget;
    lbl = new QLabel;
    lbl->setFont(f);
    mv = new QMovie(":/loading.gif");
    mv->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setMovie(mv);
    lbl->setFixedSize(200, 200);
    try_again->setFixedSize(200,100);
    try_again->setFont(f);
    buttons->setFont(f);
    back_button->setFixedSize(200,100);
    back_button->setFont(f);
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
    QLabel* picture = new QLabel;
    QFont f("Courier", 15, QFont::DemiBold);
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    picture->setPixmap(pic);
    QHBoxLayout* vert = new QHBoxLayout;
    QWidget* buttons = new QWidget;
    try_again->setFixedSize(200,100);
    try_again->setFont(f);
    buttons->setFont(f);
    back_button->setFixedSize(200,100);
    this->setFixedSize(700, 600);
    back_button->setFont(f);
    try_again->setFont(f);
//    vert->addWidget(back_button);
//    vert->addWidget(try_again);
//    buttons->setLayout(vert);
    layoutt->addWidget(back_button,4,1);
    layoutt->addWidget(try_again,4,2);
//    layoutt->addWidget(buttons,4,4);
    layoutt->addWidget(picture,3,1);
    //layoutt->setAlignment(buttons, Qt::AlignHCenter);
    this->setStyleSheet("color:black");
    this->setLayout(layoutt);
}

gametwolose::gametwolose()
{
    this->setStyleSheet("background-color:black;");
    QLabel* picture = new QLabel;
    QFont f("Courier", 15, QFont::DemiBold);
    QPixmap pic(":/you_lost.png");
    pic = pic.scaled(400,200);
    picture->setPixmap(pic);
    QHBoxLayout* vert = new QHBoxLayout;
    QWidget* buttons = new QWidget;
    try_again->setFixedSize(200,100);
    try_again->setFont(f);
    buttons->setFont(f);
    back_button->setFixedSize(200,100);
    this->setFixedSize(700, 600);
    back_button->setFont(f);
    try_again->setFont(f);
//    vert->addWidget(back_button);
//    vert->addWidget(try_again);
//    buttons->setLayout(vert);
    layoutt->addWidget(back_button,4,1);
    layoutt->addWidget(try_again,4,2);
//    layoutt->addWidget(buttons,4,4);
    layoutt->addWidget(picture,3,1);
    //layoutt->setAlignment(buttons, Qt::AlignHCenter);
    this->setStyleSheet("color:black");
    this->setLayout(layoutt);
}
