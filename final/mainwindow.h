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
#include "spacerunner.h"
#include "lose.h"
#include "game_over.h"
#include "key.h"
#include "live.h"
#include <QMediaPlayer>
#include "win_page_1.h"
#include "instructions.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    instruc* instructions = new instruc;
    doorPage* doors = new doorPage;               //main screen
    gameone* game_one = new gameone;                  //game one
    spaceRunner* firstGame = new spaceRunner(game_one);
    gametwo* game_two = new gametwo;                   //game two
    gamethree* game_three = new gamethree;              //game three
    finalpage* final_page = new finalpage;               //final page of the game
    lose* you_lose = new lose;
    gameonelose* lose_2 = new gameonelose;
    gametwolose* lose_3 = new gametwolose;
    game_over* gameover = new game_over;
    win_page_1* won = new win_page_1;
    instruction_game1* instruc_1 = new instruction_game1;
    instruction_game2* instruc_2 = new instruction_game2;
    instruction_game3* instruc_3 = new instruction_game3;
    QStackedWidget* stackWidget = new QStackedWidget;   //stacked widget for main screen and games
    //int num_keys = 1;       //key counter for whole program
    keys* num_keys = new keys;
    QStatusBar* sbar = new QStatusBar;      //status bar
    void connect_buttons();     //connects buttons to functions
    QWidget* new_win = new QWidget; //window for instructions
    lives* num_lives = new lives;
    bool flag_volume = true;
    QPushButton* volume = new QPushButton("Volume (ON/OFF)");
    QMediaPlayer* music;
    int live = 3;

public slots:
    void wait_for_gameone();
    void go_to_gameone();

    void wait_for_gametwo();
    void go_to_gametwo();


    void wait_for_gamethree();
    void go_to_gamethree();

    void go_to_main();

    void win_gameone();
    void win_gametwo();

    void waitmore_for_gamethree();
    void win_gamethree();

    void go_to_losepage();
    void turn_off();
    void lose_life();

    void wait_for_lose1();
    void lose_gameone();
    void lose_gametwo();

    void wait_for_lose2();

    void load_gif();
    void load_button();

    void go_to_instruc1();
    void go_to_instruc2();
    void go_to_instruc3();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
