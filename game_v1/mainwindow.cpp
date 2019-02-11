#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QGridLayout>
#include "door.h"
#include "doorpage.h"
#include "namepage.h"
#include <QMenuBar>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
      ui->setupUi(this);

      stackWidget->addWidget(secondWindow); // doors - index 0
      stackWidget->addWidget(check); //hello - index 1

      stackWidget->setCurrentIndex(0);


      //QObject::connect(button, SIGNAL(clicked()),d_1, SLOT(stackWidget->setCurrentWidget(1)));

      this->setCentralWidget(stackWidget);


      QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
      QMenuBar* mbar = new QMenuBar;
      QPushButton* question = new QPushButton("?");
      mbar->setCornerWidget(question);
      this->setMenuBar(mbar);

      QStatusBar* sbar = new QStatusBar;
      QLabel* key_label = new QLabel("Keys: ");
      QLabel* key_count = new QLabel;
      key_count->setNum(num_keys);
      sbar->addWidget(key_label);
      sbar->addWidget(key_count);
      setStatusBar(sbar);

      QLabel* instructions = new QLabel("Welcome to the Arcade! \n \n"
                "To start off, you are given one key and access to the first door. \n"
                "Clicking the “Enter” button underneath the door will take you inside to the first minigame. \n"
                "Within each door, you have 3 chances to beat the minigame. \n"
                "If you do, you will receive another key and return to the main menu. \n"
                "This new key opens the second door and you will face a new challenge inside. \n"
                "Collect all the keys and beat the challenges to win the game! \n");
      QWidget* new_win = new QWidget;
      QHBoxLayout* l1 = new QHBoxLayout;
      l1->addWidget(instructions);
      new_win->setLayout(l1);

      QObject::connect(question, SIGNAL(clicked()), new_win, SLOT(show()));


      QPixmap bkgnd(":/try.png");

      //bkgnd = bkgnd.scaled(10000,10000);
      bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatioByExpanding);

      QPalette palette;
      palette.setBrush(QPalette::Background, bkgnd);
      this->setPalette(palette);


}

MainWindow::~MainWindow()
{
    delete ui;
}
