#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include <QStatusBar>
#include "doorpage.h"
#include "gameone.h"
#include "gametwo.h"
#include "gamethree.h"
#include "finalpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    doorPage* firstpage = new doorPage;               //main screen
    gameone* secondpage = new gameone;                  //game one
    gametwo* thirdpage = new gametwo;                   //game two
    gamethree* fourthpage = new gamethree;              //game three
    finalpage* fifthpage = new finalpage;               //final page of the game
    QStackedWidget* stackWidget = new QStackedWidget;   //stacked widget for main screen and games
    int num_keys = 1;       //key counter for whole program
    QStatusBar* sbar = new QStatusBar;      //status bar
    void connect_buttons();     //connects buttons to functions
    QWidget* new_win = new QWidget; //window for instructions

public slots:
    void wait_forpage2();
    void wait_forpage3();
    void wait_forpage4();
    void go_to_page_2();
    void go_to_main();
    void win_gameone();
    void go_to_page_3();
    void go_to_page_4();
    void win_gametwo();
    void win_gamethree();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
