#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include "door.h"
#include "doorpage.h"
//#include "namepage.h"
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      stackWidget->addWidget(secondWindow); // doors - index 0
      stackWidget->setCurrentIndex(0);


      //QObject::connect(button, SIGNAL(clicked()),d_1, SLOT(stackWidget->setCurrentWidget(1)));

      this->setCentralWidget(stackWidget);      //central widget is stacked, so multiple screens can be shown

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
      QStatusBar* sbar = new QStatusBar;
      QLabel* key_label = new QLabel("Keys: ");         //label "keys"
      QLabel* key_count = new QLabel;                   //label with int number of keys
      key_count->setNum(num_keys);                      //num_keys member variable of mainwindow
      sbar->addWidget(key_label);
      sbar->addWidget(key_count);
      setStatusBar(sbar);                               //set status bar for central widget
      sbar->setStyleSheet("color: white");              //text color white



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

MainWindow::~MainWindow()
{
    delete ui;
}
