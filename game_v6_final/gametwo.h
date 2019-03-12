#ifndef GAMETWO_H
#define GAMETWO_H
#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <vector>
#include <string>
#include <QLabel>
#include <QString>
#include <random>
#include <QTimer>
#include <QDebug>
using std::vector;
using std::string;

extern vector<bool> check;

class Game;



/*
 * The box class inherits from QPushButton and has extra member variables int status which is set to 0
 * and bool turn_used which is set to be false. Theses two fields tell the program whether the button has
 * been clicked and that spot on the Tic Tac Toe board is being used.
 * status == 1 (player1 using the spot) status == 2 (computer using the spot)
 * turn_used === true (spot being used)
*/
class box : public QPushButton
{
    Q_OBJECT
public:
    box(QWidget* parent = 0): QPushButton(parent), status(0) {}   //defualt constructor
    int get_status() const {return status;}                    //accessor function
    void set_status(int new_stat) {status = new_stat;}         //mutator function

public slots:
    void mark() {setIcon(QIcon(":/astronaut.png"));setIconSize(QSize(65, 65));
                 setStyleSheet("font: bold; background-color: blue;");}                //puts an "X" on the pushbutton
    void change_status() {status = 1;}         //player1 using the spot
//    void spot() {turn_used = true;}       //bool spot being used
   void computer_play() {QWidget* win = new QWidget; win->show();}
private:
    int status;
};


class vec : public QObject
{
    Q_OBJECT
public:
    vec(QGridLayout* l1, QObject *parent = Q_NULLPTR): QObject(parent), turns_counter(0), layout2(l1) {}
    void set_up();
    QVector<box*> get_vec() {return my_vec;}
    box* operator[] (int index) {return my_vec[index];}
    int get_counter();                  //recounts number of turns with box variable turns_used
    void clear_board();                 //removes all box objects from vector
    bool player_win();                  //checks if a player has 3 in a row
    bool computer_win();                //checks if a computer has 3 in a row
    void draw_blank_board();
    bool get_finished() {return finished;}
public slots:
    void computer_play();
 //   void wait_for_comp();
    void check_game();
signals:
    void lose();
    void win();

private:
    QVector<box*> my_vec;
    int turns_counter;
    QGridLayout* layout2;
    bool finished;

};


/*
 * The Game class holds the code for the layout of the game. It also has the logic behind checking if the
 * player has won and determining which move the computer should make as the oppinent.
 * The member fields include an int turns_counter that stores how many turns have passed, a vector of
 * pointers to box objects and the layout of the Widget (inputted as a parametr to the Game constructor).
*/
class Game : public QObject
{
    Q_OBJECT
public:
    Game(QGridLayout* new_lay, QObject *parent = Q_NULLPTR);         //default constructor
    void connections();                 //hooks up all the signals and slots for the game
    void draw_blank_board();            //adds box objects to the gridlayout
//    void clear_board();                 //removes all box widgets from the layout
    void play_game();                   //puts functions together to start game
    int get_count() {return board->get_counter();}
    bool player_win();
    bool computer_win();
    void clear_board();
    vec* board = new vec(layout);
    QGridLayout* layout;                //3x3 grid for board
};

class gametwo : public QWidget
{
    Q_OBJECT
public:
    gametwo(); //default constructor
    QPushButton* back_button = new QPushButton();
    QPushButton* win_game_button = new QPushButton();
    QGridLayout* layoutt = new QGridLayout;
    ~gametwo();
    QWidget* ticgame = new QWidget;
    QGridLayout* l1 = new QGridLayout;
    Game* Tic_Tac_Toe = new Game(l1);
    Game* Tic_Tac_Toe2 = new Game(l1);
    Game* Tic_Tac_Toe3 = new Game(l1);
public slots:
    void reset();
    void reset2();


};


#endif // GAMETWO_H
