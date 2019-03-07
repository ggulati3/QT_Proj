#include "shooting_game.h"
#include <QDebug>
shooting_game::shooting_game()
{
    scene = new QGraphicsScene(QRect(0, 0, 600, 400));
    scene->addItem(p);
    p->setPos(400,500);
    scene->addItem(scoreboard);
    scoreboard->setTextInteractionFlags(Qt::TextEditable);
    setScene(scene);
    this->setFixedSize(800, 700);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_scoreboard()));
    timer->start(50);

}

void shooting_game::update_scoreboard(){
    scoreboard->setPlainText(QString("Score: ") + QString::number(p->score));
    if(p->score==3){        //player meets criteria for winning score
        emit won_game();
        timer->stop();
    }

    if(p->lost){            //player has lost
        emit lose_game();
        p->lost = false;
        p->score = 0;
        //timer->stop();
    }
}


void shooting_game::keyPressEvent(QKeyEvent *event){
        if (event->key() == Qt::Key_Left){      //if left key is pressed, move player left
            if (p->pos().x() > -110)
               p->setPos(p->pos().x()-10,p->pos().y());
        }
        else if (event->key() == Qt::Key_Right){ //if right key is pressed, move player right
             if (p->pos().x() < 660)
               p->setPos(p->pos().x()+10,p->pos().y());
        }
        else if(event->key()==Qt::Key_Space){   //if spacebar is pressed, create new bullet and add to scene
            bullet * b = new bullet(p);
            b->setPos(p->pos().x()-25,p->pos().y()-25);
            scene->addItem(b);
        }
}

shooting_game::~shooting_game(){
    delete scene;
}

player::player()
{
    setPixmap(QPixmap (":/ship.png").scaled(50,50));
    QObject::connect(timer,SIGNAL(timeout()), this,SLOT(spawn()));
    timer->start(2000);
}

void player::spawn(){
    enemy* e = new enemy(this);
    scene()->addItem(e);
}

bullet::bullet( player* p ):owner(p)
{
    setPixmap(QPixmap (":/bullet.png").scaled(100,100));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void bullet::move(){
    setPos(this->pos().x() ,pos().y()-20);  //move bullet up by 20
    QList<QGraphicsItem*> colliding_items=this->collidingItems();
        for(int i = 0; i < colliding_items.size(); ++i){    //iterates through list of collidingItems() with this bullet
            if(typeid(*(colliding_items[i])) == typeid(enemy))  //if bullet collides with an enemy delete both objects and free memory
            {
                    owner->score++;
                    scene()->removeItem(colliding_items[i]);
                    scene()->removeItem(this);
                    delete colliding_items[i];
                    delete this;
                    return;
            }
        }
    if (pos().y() < 0){                     //deletes bullet if off screen
            scene()->removeItem(this);
            delete this;
        }
}

enemy::enemy(player* play): p(play)
{
    int random_number = rand() % 700;
    setPos(random_number,0);
    setPixmap(QPixmap(":/enemy.png").scaled(20,20));
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

/* function that moves the enemy down the screen
 * @param N/A
 * @return N/A
 * */
void enemy::move(){
    setPos(x(),y()+5);

    QList<QGraphicsItem*> colliding_items=this->collidingItems();
       for(int i = 0; i < colliding_items.size(); ++i){    //iterates through list of colliding items with enemy
           if(typeid(*(colliding_items[i])) == typeid(player))     //if item colliding with this enemy is a player, remove both from scene and free memory
           {
                   p->lost= true;
                   //scene()->removeItem(colliding_items[i]);
                   scene()->removeItem(this);
                   //p->timer->stop();
                   //delete p->timer;
                   //delete colliding_items[i];
                   delete this;
                   return;
           }
       }


    if (pos().y() > 700){
            scene()->removeItem(this);
            delete this;
        }
}


