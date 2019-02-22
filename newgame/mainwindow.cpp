#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include "door.h"
#include "doorpage.h"
#include "key.h"
#include <QMenuBar>
#include <QPixmap>
#include <QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      // added music

      QMediaPlayer* music = new QMediaPlayer();
      music->setMedia(QUrl::fromLocalFile("/Users/gauravgulati/desktop/newgame/music.mp3"));
      music->play();


      stackWidget->addWidget(firstpage); // doors - index 0
      stackWidget->addWidget(secondpage); //game one - index 1
      stackWidget->addWidget(thirdpage); //game two - index 2
      stackWidget->setCurrentIndex(0);
      this->setCentralWidget(stackWidget);      //central widget is stacked, so multiple screens can be shown

      connect_buttons();

    /*
     * Create a menu bar on the tope of the screen, with a pushbutton "?".
     * Clicking the button opens a new window with the game instructions.
     */
      QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);      //menu bar fix for Macs
      QMenuBar* mbar = new QMenuBar;
      QPushButton* question = new QPushButton("?");         //pushbutton
      mbar->setCornerWidget(question);                      //set pushbutton to right corner of menu bar
      this->setMenuBar(mbar);                               //set menu bar for central widget

      //game instructions
      QLabel* instructions = new QLabel("Welcome to the Arcade! \n \n"
                "To start off, you are given one key and access to the first door. \n"
                "Clicking the “Enter” button underneath the door will take you inside to the first minigame. \n"
                "Within each door, you have 3 chances to beat the minigame. \n"
                "If you do, you will receive another key and return to the main menu. \n"
                "This new key opens the second door and you will face a new challenge inside. \n"
                "Collect all the keys and beat the challenges to win the game! \n");
      QWidget* new_win = new QWidget;           //new window
      QHBoxLayout* l1 = new QHBoxLayout;
      l1->addWidget(instructions);              //add label
      new_win->setFixedSize(600, 200);
      new_win->setLayout(l1);

      QObject::connect(question, SIGNAL(clicked()), new_win, SLOT(show()));     //connect pushbutton and new window

      /*
       * Create a title label for the main window.
       */
      QLabel* title = new QLabel("Arcade 10C");         //title
      title->setStyleSheet("color: pink");              //label color
      QFont f("Bauhaus 93", 30, QFont::Bold);           //font type and size
      title->setFont(f);
      title->move(80, -125);                            //set location in the window
      layout()->addWidget(title);

      /*
       * Create a status bar on the bottom of the screen.
       * The status bar has two labels that show the user how many keys they have.
       */
      QLabel* key_label = new QLabel("Keys: ");         //label "keys"
      sbar->addWidget(key_label);
      key* new_key = new key;                           //create and add one key
      sbar->addWidget(new_key);
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
void MainWindow::go_to_page_2(){
    stackWidget->setCurrentIndex(1);
}

/* Function to go to page 3/game 2
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_page_3(){
    stackWidget->setCurrentIndex(2);
}

/* Function to return to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::go_to_main(){
    stackWidget->setCurrentIndex(0);
}

/* Function to update status bar and change window back from game one to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gameone(){
    key* new_key = new key;
    sbar->addWidget(new_key);
    setStatusBar(sbar);
    firstpage->layout->addWidget(firstpage->button_2, 1, 1, 5, 1);
    stackWidget->setCurrentIndex(0);
}

/* Function to update status bar and change window back from game two to main screen
 * @param N/A
 * @return N/A
 * */
void MainWindow::win_gametwo(){
    key* new_key = new key;
    sbar->addWidget(new_key);
    setStatusBar(sbar);
    firstpage->layout->addWidget(firstpage->button_3, 1, 2, 5, 1);
    stackWidget->setCurrentIndex(0);
}

/* Function to connect all the buttons to transition between windows
 * @param N/A
 * @return N/A
 * */
void MainWindow::connect_buttons(){
    QObject::connect(firstpage->button,SIGNAL(clicked()), this, SLOT(go_to_page_2())); //clicking enter button goes from first page to second page
    QObject::connect(secondpage->back_button,SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button goes back to first page
    QObject::connect(secondpage->win_game_button,SIGNAL(clicked()), this, SLOT(win_gameone())); //simulating winning game one, returning to main page
    QObject::connect(firstpage->button_2,SIGNAL(clicked()), this, SLOT(go_to_page_3())); //clicking second enter button goes from frist page to third page
    QObject::connect(thirdpage->back_button,SIGNAL(clicked()), this, SLOT(go_to_main())); //clicking back_button goes back to first page
    QObject::connect(thirdpage->win_game_button,SIGNAL(clicked()), this, SLOT(win_gametwo())); //simulating winning game one, returning to main page
}

/* destructor
 * @param N/A
 * @return N/A
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete firstpage;
    delete secondpage;
    delete thirdpage;
    delete stackWidget;
    delete sbar;
}
