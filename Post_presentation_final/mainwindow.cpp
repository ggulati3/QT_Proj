#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include "door.h"
#include "doorpage.h"
#include "key.h"
#include <QMenuBar>
#include <QPixmap>
#include <QTimer>
#include <QMediaPlayer>
#include <QSpacerItem>

/* constructor for the main window of the application
 * @param parent
 * @return N/A
 * */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      stackWidget->addWidget(doors); // doors - index 0
      stackWidget->addWidget(game_one); //game one - index 1
      stackWidget->addWidget(game_two); //game two - index 2
      stackWidget->addWidget(game_three); //game three - index 3
      stackWidget->addWidget(final_page); //final page - index 4
      stackWidget->addWidget(you_lose); //lose page index 5
      stackWidget->addWidget(gameover); // index 6
      stackWidget->addWidget(lose_2); // index 7
      stackWidget->addWidget(lose_3); // index 8
      stackWidget->addWidget(won);  //index 9
      stackWidget->addWidget(instruc_1);//index 10
      stackWidget->addWidget(instruc_2); //index 11
      stackWidget->addWidget(instruc_3); //index 12
      stackWidget->addWidget(instructions); //index 13
      stackWidget->setCurrentIndex(2);
      this->setCentralWidget(stackWidget);      //central widget is stacked, so multiple screens can be shown
      layout()->setAlignment(stackWidget, Qt::AlignCenter);

      connect_buttons();

      music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/music.mp3"));
      music->play();


      /*
       * Create a title label for the main window.
       */
      QLabel* title = new QLabel;
      QPixmap pic(":/title.png");
      pic = pic.scaled(200,95);
      title->setPixmap(pic);
      title->move(1000, -155);                            //set location in the window
      layout()->addWidget(title);

      /*
       * Create a status bar on the bottom of the screen.
       * The status bar has two labels that show the user how many keys they have.
       */
      QFont* f= new QFont("Courier", 15, QFont::DemiBold);
      QLabel* key_label = new QLabel("Keys: ");         //label "keys"
      key_label->setFont(*f);
      key_label->setStyleSheet("color: black");//create and add one key
      sbar->addWidget(key_label);
      sbar->addWidget(num_keys);
      QLabel* lives_label = new QLabel("Lives: ");         //label "lives"
      lives_label->setFont(*f);
      lives_label->setStyleSheet("color: black");
      sbar->addWidget(lives_label);
      sbar->addWidget(num_lives);

      volume->setIcon(QIcon(":/volume.png"));
      volume->setFixedSize(50,50);
      sbar->addWidget(volume);

      setStatusBar(sbar);                               //set status bar for central widget
      sbar->setStyleSheet("color: white");              //text color black

    /*
     * Import and set the background picture.
     */
      QPixmap bkgnd(":/background.png");
      bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);
      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);    //set backgoruns
      this->setPalette(palette);

      this->setFixedSize(1200, 800);       //set fixed size for window
}

/* Function to go to game 1
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gameone(){
    stackWidget->setCurrentIndex(1);
}

/* Function to go to game 2
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gametwo(){
    stackWidget->setCurrentIndex(2);
}


/* Function to go to game 3, start player timer, set player position, and stop deleting enemies(set delete_enemies=false)
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gamethree(){
    game_three->game->p->timer->start();
    game_three->game->p->setPos(400,game_three->game->p->pos().y());
    game_three->game->p->delete_enemies=false;
    stackWidget->setCurrentIndex(3);
}

/* Function to return to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_main(){
    game_three->game->p->setPos(900,game_three->game->p->pos().y());
    stackWidget->setCurrentIndex(0);
}

/* Function to update status bar after winning gameone, and change window back from game one to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gameone(){
    num_keys->layout->addWidget((num_keys->key_2));
    setStatusBar(sbar);
    (doors->d_2->door_lay)->addWidget(doors->button_2);
    stackWidget->setCurrentIndex(9);
}

/* function that goes to game one instructions after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gameone(){
    QTimer::singleShot(400, this, SLOT(go_to_instruc1()));
}

/* function that goes to game two instructions after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gametwo(){
    QTimer::singleShot(400, this, SLOT(go_to_instruc2()));
}


/* function that goes to game three instructions after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gamethree(){
    QTimer::singleShot(400, this, SLOT(go_to_instruc3()));
}

/* function that goes to game three page after a 6000ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::waitmore_for_gamethree(){
    QTimer::singleShot(6000, this, SLOT(go_to_gamethree()));
}

/* Function to update status bar and change window back from game two to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gametwo(){
    num_keys->layout->addWidget((num_keys->key_3));
    setStatusBar(sbar);
    (doors->d_3->door_lay)->addWidget(doors->button_3);
    stackWidget->setCurrentIndex(9);
}

/* Function to change window back from game three to final page
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gamethree(){
     game_three->game->p->setPos(900,game_three->game->p->pos().y());
    stackWidget->setCurrentIndex(4);
}

/* Function to go to either a lose page or a game over page after losing game one, depending on # of lives left. This function also updates the lives counter.
 * @param N/A
 * @return N/A
 * */
void MainWindow::lose_gameone(){
    lose_life();
    if(live==2){
        num_lives->layoutt->removeWidget((num_lives->live_1));
    }
    if(live==1){
        num_lives->layoutt->removeWidget((num_lives->live_2));
    }
    if(live==0){
        num_lives->layoutt->removeWidget((num_lives->live_3));
    }
    setStatusBar(sbar);
    if(live > 0)
        stackWidget->setCurrentIndex(7);
    else {
        stackWidget->setCurrentIndex(6);
    }

    if(game_one->game->gameOver) {
        game_one->game->resetGame();
    }

}

/* Function to go to either a lose page or a game over page after losing game two, depending on # of lives left. This function also updates the lives counter.
 * @param N/A
 * @return N/A
 * */
void MainWindow::lose_gametwo(){
    lose_life();
    if(live==2){
        num_lives->layoutt->removeWidget((num_lives->live_1));
    }
    if(live==1){
        num_lives->layoutt->removeWidget((num_lives->live_2));
    }
    if(live==0){
        num_lives->layoutt->removeWidget((num_lives->live_3));
    }
    setStatusBar(sbar);
    if(live > 0)
        stackWidget->setCurrentIndex(8);
    else {
        stackWidget->setCurrentIndex(6);
    }
}

/* Function to go to either a lose page or a game over page after losing game three, depending on # of lives left. This function also updates the lives counter.
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_losepage(){  
    lose_life();
    game_three->game->p->setPos(900,game_three->game->p->pos().y());
    if(live==2){
        num_lives->layoutt->removeWidget((num_lives->live_1));
    }
    if(live==1){
        num_lives->layoutt->removeWidget((num_lives->live_2));
    }
    if(live==0){
        num_lives->layoutt->removeWidget((num_lives->live_3));
    }
    setStatusBar(sbar);
    if(live > 0)
        stackWidget->setCurrentIndex(5);
    else {
        stackWidget->setCurrentIndex(6);
    }
}

/* function that moves stackedwidget to index 10- displaying instructions for game one
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_instruc1(){
    stackWidget->setCurrentIndex(10);
}


/* function that moves stackedwidget to index 11- displaying instructions for game two
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_instruc2(){
    stackWidget->setCurrentIndex(11);
}


/* function that moves stackedwidget to index 12- displaying instructions for game three
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_instruc3(){
    stackWidget->setCurrentIndex(12);
}


/* Function to connect all the buttons to transition between windows
 * @param N/A
 * @return N/A
 * */
void MainWindow::connect_buttons(){
    QObject::connect(doors->button,SIGNAL(clicked()), this, SLOT(wait_for_gameone())); //clicking enter button goes from main page to gameone
    QObject::connect(doors->button_2,SIGNAL(clicked()), this, SLOT(wait_for_gametwo())); //clicking second enter button goes from main page to game two
    QObject::connect(doors->button_3,SIGNAL(clicked()), this, SLOT(wait_for_gamethree())); //clicking third enter button goes from main page to game three
    QObject::connect(instructions->start, SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking start on instructions page takes you to main page
    QObject::connect(instruc_1->back, SIGNAL(clicked()), this, SLOT(go_to_main()));// clicking back on instruc_1 takes you to main page
    QObject::connect(instruc_2->back, SIGNAL(clicked()), this, SLOT(go_to_main()));// clicking back on instruc_2 takes you to main page
    QObject::connect(instruc_3->back, SIGNAL(clicked()), this, SLOT(go_to_main()));// clicking back on instruc_3 takes you to main page
    QObject::connect(instruc_1->start, SIGNAL(clicked()), this, SLOT(go_to_gameone()));// clicking start on instruc_1 takes you to gameone
    QObject::connect(instruc_2->start, SIGNAL(clicked()), this, SLOT(go_to_gametwo()));// clicking start on instruc_2 takes you to gametwo
    QObject::connect(instruc_3->start, SIGNAL(clicked()), this, SLOT(go_to_gamethree()));// clicking start on instruc_3 takes you to gamethree
    QObject::connect(lose_2->back_button, SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button on lose_2(game 1 you lose page) goes to main screen
    QObject::connect(lose_2->try_again, SIGNAL(clicked()), this, SLOT(go_to_gameone()));//clicking try_again on lose_2(game 1 you lose page) goes to game 1
    QObject::connect(game_three->game,SIGNAL(won_game()), this, SLOT(win_gamethree())); // winning game three-> 'you win' page
    QObject::connect(game_three->game, SIGNAL(lose_game()), this, SLOT(go_to_losepage())); // losing game three-> 'you lose' page
    QObject::connect(game_two->Tic_Tac_Toe2->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));//losing game two(try 2)->'you lose' page
    QObject::connect(game_two->Tic_Tac_Toe2->board, SIGNAL(win()), this, SLOT(win_gametwo()));//winning game two(try 2)->'you win page'
    QObject::connect(game_two->Tic_Tac_Toe3->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));//losing game two(try 3)->'you lose' page
    QObject::connect(game_two->Tic_Tac_Toe3->board, SIGNAL(win()), this, SLOT(win_gametwo()));//winning game two(try 3)->'you win page'
    QObject::connect(game_two->Tic_Tac_Toe->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));//losing game two(try 1)->'you lose' page
    QObject::connect(game_two->Tic_Tac_Toe->board, SIGNAL(win()), this, SLOT(win_gametwo()));//winning game two(try 1)->'you win page'
    QObject::connect(you_lose->back_button, SIGNAL(clicked()), this, SLOT(go_to_main()));//clicking back_button on game1losepage->main page
    QObject::connect(you_lose->try_again, SIGNAL(clicked()), this, SLOT(go_to_gamethree()));//clicking try_again on game1losepage->gamethree
    QObject::connect(game_one->game, SIGNAL(endGame()), this, SLOT(lose_gameone()));//losing game one->lose game 1 page
    QObject::connect(game_one->game, SIGNAL(winGame()), this, SLOT(win_gameone()));// winning game one-> win game 1 page
    QObject::connect(lose_3->back_button, SIGNAL(clicked()), this, SLOT(go_to_main()));//clicking back_button on game 2 lose page->main page
    QObject::connect(lose_3->try_again, SIGNAL(clicked()), this, SLOT(go_to_gametwo()));//clicking try_again on game2 lose page->game two
    QObject::connect(won->win_game_button, SIGNAL(clicked()), this, SLOT(go_to_main())); // clicking button on a winpage-> main screen
    QObject::connect(volume, SIGNAL(clicked()), this, SLOT(turn_off()));    //clicking volume button turns background music off(and on)

}

/* destructor for MainWindow
 * @param N/A
 * @return N/A
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::turn_off(){
    if(flag_volume) {
        flag_volume = false;
        music->setVolume(0);
    } else {
        flag_volume = true;
        music->setVolume(50);
    }
}

/* function that decrements the live counter
 * @param N/A
 * @return N/A
*/
void MainWindow::lose_life(){
    live--;
}
