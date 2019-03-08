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
      stackWidget->setCurrentIndex(9);
      this->setCentralWidget(stackWidget);      //central widget is stacked, so multiple screens can be shown

      connect_buttons();

      music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/music.mp3"));
      music->play();


      /*
           * Create a menu bar on the tope of the screen, with a pushbutton "?".
           * Clicking the button opens a new window with the game instructions.
           */
            QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);      //menu bar fix for Macs
            QMenuBar* mbar = new QMenuBar;
            QPushButton* question = new QPushButton("?");         //pushbutton
            mbar->setCornerWidget(question, Qt::TopRightCorner); //set pushbutton to right corner of menu bar
            mbar->setCornerWidget(volume, Qt::TopLeftCorner);
            this->setMenuBar(mbar);                               //set menu bar for central widget


            //game instructions

      //game instructions

      QLabel* instructions = new QLabel("Welcome to the Arcade! \n \n"
                "To start off, you are given one key and access to the first door. \n"
                "Clicking the “Enter” button underneath the door will take you inside to the first minigame. \n"
                "Within each door, you have 3 chances to beat the minigame. \n"
                "If you do, you will receive another key and return to the main menu. \n"
                "This new key opens the second door and you will face a new challenge inside. \n"
                "Collect all the keys and beat the challenges to win the game! \n");
      QHBoxLayout* l1 = new QHBoxLayout;
      l1->addWidget(instructions);              //add label
      new_win->setFixedSize(650, 375);
      new_win->setLayout(l1);
      QObject::connect(question, SIGNAL(clicked()), new_win, SLOT(show()));     //connect pushbutton and new window

      /*
       * Create a title label for the main window.
       */
      QLabel* title = new QLabel("Arcade 10C");         //title
      title->setStyleSheet("color: pink");              //label color
      title->setFixedSize(700, 100);
      QFont f("Bauhaus 93", 30, QFont::Bold);           //font type and size
      title->setFont(f);
      title->move(50, 50);                            //set location in the window
      layout()->addWidget(title);

      /*
       * Create a status bar on the bottom of the screen.
       * The status bar has two labels that show the user how many keys they have.
       */
      QLabel* key_label = new QLabel("Keys: ");         //label "keys"
      key_label->setStyleSheet("color: black");//create and add one key
      sbar->addWidget(key_label);
     // key* new_key = new key;
      sbar->addWidget(num_keys);
      QLabel* lives_label = new QLabel("Lives: ");         //label "lives"
      lives_label->setStyleSheet("color: black");
      sbar->addWidget(lives_label);
      sbar->addWidget(num_lives);
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

/* Function to go to page 2/game 1
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gameone(){
    stackWidget->setCurrentIndex(1);
}

/* Function to go to page 3/game 2
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gametwo(){
    stackWidget->setCurrentIndex(2);
}


/* Function to go to page 4/game 3
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_gamethree(){
    game_three->game->p->timer->start();
    game_three->game->p->setPos(400,game_three->game->p->pos().y());
    /*if(live == 3)
        game_three->game->p->timer->start();
    if(live == 2)
        game_three->game_2->p->timer->start();
    if(live == 1)
        game_three->game_3->p->timer->start();
        */
    stackWidget->setCurrentIndex(3);
}

/* Function to return to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_main(){
    game_three->game->p->setPos(900,game_three->game->p->pos().y());
   // game_three->game_2->p->setPos(900,game_three->game->p->pos().y());
   // game_three->game_3->p->setPos(900,game_three->game->p->pos().y());

    stackWidget->setCurrentIndex(0);
}

/* Function to update status bar and change window back from game one to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gameone(){
    num_keys->layout->addWidget((num_keys->key_2));
    setStatusBar(sbar);
    (doors->d_2->door_lay)->addWidget(doors->button_2);
    stackWidget->setCurrentIndex(9);
}

/* function that goes to page 2 after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gameone(){
    QTimer::singleShot(400, this, SLOT(go_to_gameone()));
}

/* function that goes to page 3 after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gametwo(){
    QTimer::singleShot(400, this, SLOT(go_to_gametwo()));
}

void MainWindow::wait_for_lose1(){
    QTimer::singleShot(2000, this, SLOT(lose_gameone()));
}

void MainWindow::wait_for_lose2(){
    QTimer::singleShot(2000, this, SLOT(lose_gametwo()));
}

/* function that goes to page 4 after a 400ms delay
 * @param N/A
 * @return N/A
 * */
void MainWindow::wait_for_gamethree(){
    QTimer::singleShot(400, this, SLOT(go_to_gamethree()));
}

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
     /*
     game_three->game_2->p->setPos(900,game_three->game->p->pos().y());
     game_three->game_3->p->setPos(900,game_three->game->p->pos().y());
     */
    stackWidget->setCurrentIndex(4);
}

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

void MainWindow::go_to_losepage(){  
    lose_life();

    if(live==2){
        game_three->game->p->setPos(900,game_three->game->p->pos().y());
        num_lives->layoutt->removeWidget((num_lives->live_1));
    }
    if(live==1){
        game_three->game->p->setPos(900,game_three->game->p->pos().y());
       // game_three->game_2->p->setPos(900,game_three->game->p->pos().y());
        num_lives->layoutt->removeWidget((num_lives->live_2));
    }
    if(live==0){
        game_three->game->p->setPos(900,game_three->game->p->pos().y());
        //game_three->game_3->p->setPos(900,game_three->game->p->pos().y());
        num_lives->layoutt->removeWidget((num_lives->live_3));
    }
     /**/
    setStatusBar(sbar);
    if(live > 0)
        stackWidget->setCurrentIndex(5);
    else {
        stackWidget->setCurrentIndex(6);
    }
}

/* Function to connect all the buttons to transition between windows
 * @param N/A
 * @return N/A
 * */
void MainWindow::connect_buttons(){
    QObject::connect(doors->button,SIGNAL(clicked()), this, SLOT(wait_for_gameone())); //clicking enter button goes from first page to second page
    QObject::connect(game_one->back_button,SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button goes back to first page
    QObject::connect(game_one->win_game_button,SIGNAL(clicked()), this, SLOT(win_gameone())); //simulating winning game one, returning to main page
    QObject::connect(doors->button_2,SIGNAL(clicked()), this, SLOT(wait_for_gametwo())); //clicking second enter button goes from first page to third page
    QObject::connect(game_two->back_button,SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button goes back to first page
    QObject::connect(game_two->win_game_button,SIGNAL(clicked()), this, SLOT(win_gametwo())); //simulating winning game two, returning to main page
    QObject::connect(doors->button_3,SIGNAL(clicked()), this, SLOT(wait_for_gamethree())); //clicking third enter button goes from first page to fourth page
    QObject::connect(game_three->back_button,SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button goes back to first page
    QObject::connect(lose_2->back_button, SIGNAL(clicked()), this, SLOT(go_to_main()));
    QObject::connect(lose_2->try_again, SIGNAL(clicked()), this, SLOT(go_to_gameone()));


    QObject::connect(game_three->game,SIGNAL(won_game()), this, SLOT(win_gamethree())); // winning game three
    QObject::connect(game_three->game, SIGNAL(lose_game()), this, SLOT(go_to_losepage())); // losing game three, returning to main page
    /*
    QObject::connect(game_three->game_2,SIGNAL(won_game()), this, SLOT(win_gamethree())); // winning game three
    QObject::connect(game_three->game_2, SIGNAL(lose_game()), this, SLOT(go_to_losepage())); // losing game three, returning to main page
    QObject::connect(game_three->game_3,SIGNAL(won_game()), this, SLOT(win_gamethree())); // winning game three
    QObject::connect(game_three->game_3, SIGNAL(lose_game()), this, SLOT(go_to_losepage())); // losing game three, returning to main page
*/
    QObject::connect(game_two->Tic_Tac_Toe2->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));
    QObject::connect(game_two->Tic_Tac_Toe2->board, SIGNAL(win()), this, SLOT(win_gametwo()));
    QObject::connect(game_two->Tic_Tac_Toe3->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));
    QObject::connect(game_two->Tic_Tac_Toe3->board, SIGNAL(win()), this, SLOT(win_gametwo()));
    QObject::connect(you_lose->back_button, SIGNAL(clicked()), this, SLOT(go_to_main()));
    QObject::connect(you_lose->try_again, SIGNAL(clicked()), this, SLOT(waitmore_for_gamethree()));
    QObject::connect(game_one->game, SIGNAL(endGame()), this, SLOT(lose_gameone()));
    QObject::connect(game_one->game, SIGNAL(winGame()), this, SLOT(win_gameone()));
    QObject::connect(game_two->Tic_Tac_Toe->board, SIGNAL(lose()), this, SLOT(lose_gametwo()));
    QObject::connect(game_two->Tic_Tac_Toe->board, SIGNAL(win()), this, SLOT(win_gametwo()));
    QObject::connect(lose_3->back_button, SIGNAL(clicked()), this, SLOT(go_to_main()));
    QObject::connect(lose_3->try_again, SIGNAL(clicked()), this, SLOT(go_to_gametwo()));
    QObject::connect(won->win_game_button, SIGNAL(clicked()), this, SLOT(go_to_main()));
    QObject::connect(volume, SIGNAL(clicked()), this, SLOT(turn_off()));
}

/* destructor
 * @param N/A
 * @return N/A
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete new_win;
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


void MainWindow::lose_life(){
    live--;
/*
    if(live==2){
        game_three->layoutt->removeWidget(game_three->game);
        game_three->layoutt->addWidget(game_three->game_2,4,4);
    }
    if(live==1){
        game_three->layoutt->removeWidget(game_three->game_2);
        game_three->layoutt->addWidget(game_three->game_3,4,4);
    }
    */
}
