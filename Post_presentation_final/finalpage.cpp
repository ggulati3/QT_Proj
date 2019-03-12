#include "finalpage.h"
#include "QPixmap"
#include <QMovie>
/* default constructor, placeholder trophy image
 * @param N/A
 * @return N/A
 * */
finalpage::finalpage()
{
    QLabel* trophy = new QLabel;
    QPixmap pic(":/pixel.png");
    pic = pic.scaled(200,300);
    trophy->setPixmap(pic);
    layout->addWidget(trophy,1,0);

    QLabel* winner = new QLabel;
    QPixmap pict(":/winner.png");
    pict = pict.scaled(200,300);
    winner->setPixmap(pict);
    winner->setScaledContents(100);
    layout->addWidget(winner,1,1);

    QLabel *lbl = new QLabel;
    QLabel *lbl2 = new QLabel;
    QLabel *lbl3 = new QLabel;
    QMovie *mv = new QMovie(":/stars.gif");
    QMovie *mv2 = new QMovie(":/stars.gif");
    QMovie *mv3 = new QMovie(":/stars.gif");
    mv->start();
    mv2->start();
    mv3->start();
    lbl->setAttribute(Qt::WA_NoSystemBackground);
    lbl2->setAttribute(Qt::WA_NoSystemBackground);
    lbl->setScaledContents(50);
    lbl2->setScaledContents(50);
    lbl->setMovie(mv);
    lbl2->setMovie(mv);
    lbl3->setMovie(mv);
    layout->addWidget(lbl,2,0);
    layout->addWidget(lbl2, 2,2);
    layout->addWidget(lbl3, 2,1);
    setLayout(layout);
}
