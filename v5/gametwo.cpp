#include "gametwo.h"
#include <QDebug>

/* constructor of game 2
 * @param N/A
 * @return N/A
 * */
gametwo::gametwo()
{
    layoutt->addWidget(back_button, 1, 0);          //add back button
    layoutt->addWidget(win_game_button, 1, 2);      //add win button
    this->setLayout(layoutt);

    //create a game widget and set backgorund image to be a tic tac toe board
    ticgame->setStyleSheet("*{background-image: url(:/ticboard.png);}");
    layoutt->addWidget(ticgame, 0, 1);          //put in center of game2 layoutt
    ticgame->setFixedSize(600, 600);
    ticgame->setLayout(l1);                     //set game widget to have grid layout

        Tic_Tac_Toe->play_game();        //runs game

}

/* destructor of game 2
 * @param N/A
 * @return N/A
 * */
gametwo::~gametwo() {}

void vec::set_up()
{
    const QSize b_size = QSize(70,70);          //size
    my_vec.resize(10);
    for (int i=0; i < 10; i++)              //9 objects
    {
        my_vec[i] = new box();               //create box object and add to the vector
        my_vec[i]->setFixedSize(b_size);     //set fixed size
    }
}


/*
 * Default constructor for Game(). Sets layout to param new_lay and int = 0.
 * This also creates 9 box objects of fixed size (pushbuttons) and adds them to the vector<box*> board.
 * @param: QGridLayout* new_lay
 * @return: N/A
*/
Game::Game(QGridLayout* new_lay, QObject *parent) : layout(new_lay)	//default constructor
{
    board->set_up();

}

/*
 * The connections() function codes all the QObject::connect for the necessary signals and slots for the game.
 * @param: N/A
 * @return: N/A
*/
void Game::connections()
{
    for (int i=0; i< 10; i++)       //connect for all 9 box objects in the vector
    {
        QObject::connect((*board)[i], SIGNAL(clicked()), (*board)[i], SLOT(mark()));              //sets the text of box pushbutton to be "X"
        QObject::connect((*board)[i], SIGNAL(clicked()), (*board)[i], SLOT(change_status()));
        QObject::connect((*board)[i], SIGNAL(clicked()), board, SLOT(computer_play()));
        QObject::connect((*board)[i], SIGNAL(clicked()), board, SLOT(check_game()));

    }
}

/*
 * The draw_blank_board() function adds all 9 objects of board vector to the layout (3x3 grid).
 * @param: N/A
 * @return: N/A
*/
void Game::draw_blank_board()
{
    for (int i=0; i<3; ++i)         //3 rows
    {
       for (int j=0; j < 3; ++j)    //3 columns
       {
           layout->addWidget((*board)[j + i*3], 0+i, j);       //start with first row and add 3 objects to (0,0) (0,1) (0,2)
       }
    }
}

/*
 * The play_game() function draws the board and then hooks up all the connections.
 * From here, the user can click their first spot and the game with run itself.
 * @param: N/A
 * @return: N/A
*/
void Game::play_game()
{
   draw_blank_board();      //add 9 box objects
   connections();           //set us necessary game connections

}

/*
 * The clear_board() function removes the box pushbuttons from the layout after a game has been played.
 * @param: N/A
 * @return: N/A
*/
void vec::clear_board()
{
    for (int i=0; i < 10; i++)            //all 9 objects
    {
        my_vec.pop_back();              //remove each box from the vector
    }
    for (int i=0; i < 10; i++)            //all 9 objects
    {
        layout2->removeWidget(my_vec[i]);        //remove each box from the layout
    }
}

//void vec::draw_blank_board()
//{
//    for (int i=0; i<3; ++i)         //3 rows
//    {
//       for (int j=0; j < 3; ++j)    //3 columns
//       {
//           layout2->addWidget(my_vec[j + i*3], 0+i, j);       //start with first row and add 3 objects to (0,0) (0,1) (0,2)
//       }
//    }
//}

void vec::check_game()
{
    if (player_win() == true || computer_win() == true || get_counter() == 9)
    {
        finished = true;
        if (player_win()==true)
            emit win();
        else {
            emit lose();
        }
    }
}

/*
 * The function player_win() creates and returns a bool check which is true if player1 has 3 in a row, column or diagonal.
 * @param: N/A
 * @return: N/A
*/
bool vec::player_win()
{
    bool check;         //create bool

    if (my_vec[0]->get_status() == 1 && my_vec[1]->get_status() == 1 && my_vec[2]->get_status() == 1)          //1st row
        check = true;
    else if (my_vec[3]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[5]->get_status() == 1)     //2nd row
        check = true;
    else if (my_vec[6]->get_status() == 1 && my_vec[7]->get_status() == 1 && my_vec[8]->get_status() == 1)     //3rd row
        check = true;
    else if (my_vec[0]->get_status() == 1 && my_vec[3]->get_status() == 1 && my_vec[6]->get_status() == 1)     //1st column
        check = true;
    else if (my_vec[1]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[7]->get_status() == 1)     //2nd column
        check = true;
    else if (my_vec[2]->get_status() == 1 && my_vec[5]->get_status() == 1 && my_vec[8]->get_status() == 1)     //3rd column
        check = true;
    else if (my_vec[0]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[8]->get_status() == 1)     //left diagonal
        check = true;
    else if (my_vec[2]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[6]->get_status() == 1)     //right diagonal
        check = true;
    else
        check = false;		// player1 has not won yet

    return check;
}

/*
 * The function computer_win() creates and returns a bool check which is true if computer has 3 in a row, column or diagonal.
 * @param: N/A
 * @return: N/A
*/
bool vec::computer_win()
{
    bool check;            //create bool

    if (my_vec[0]->get_status() == 2 && my_vec[1]->get_status() == 2 && my_vec[2]->get_status() == 2)          //1st row
        check = true;
    else if (my_vec[3]->get_status() == 2 && my_vec[4]->get_status() == 2 && my_vec[5]->get_status() == 2)     //2nd row
        check = true;
    else if (my_vec[6]->get_status() == 2 && my_vec[7]->get_status() == 2 && my_vec[8]->get_status() == 2)     //3rd row
        check = true;
    else if (my_vec[0]->get_status() == 2 && my_vec[3]->get_status() == 2 && my_vec[6]->get_status() == 2)     //1st column
        check = true;
    else if (my_vec[1]->get_status() == 2 && my_vec[4]->get_status() == 2 && my_vec[7]->get_status() == 2)     //2nd column
        check = true;
    else if (my_vec[2]->get_status() == 2 && my_vec[5]->get_status() == 2 && my_vec[8]->get_status() == 2)     //3rd column
        check = true;
    else if (my_vec[0]->get_status() == 2 && my_vec[4]->get_status() == 2 && my_vec[8]->get_status() == 2)     //left diagonal
        check = true;
    else if (my_vec[2]->get_status() == 2 && my_vec[4]->get_status() == 2 && my_vec[6]->get_status() == 2)     //right diagonal
        check = true;
    else
        check = false;		// computer has not won yet

    return check;
}

bool Game::player_win()
{
    bool check;         //create bool

    if ((*board)[0]->get_status() == 1 && (*board)[1]->get_status() == 1 && (*board)[2]->get_status() == 1)          //1st row
        check = true;
    else if ((*board)[3]->get_status() == 1 && (*board)[4]->get_status() == 1 && (*board)[5]->get_status() == 1)     //2nd row
        check = true;
    else if ((*board)[6]->get_status() == 1 && (*board)[7]->get_status() == 1 && (*board)[8]->get_status() == 1)     //3rd row
        check = true;
    else if ((*board)[0]->get_status() == 1 && (*board)[3]->get_status() == 1 && (*board)[6]->get_status() == 1)     //1st column
        check = true;
    else if ((*board)[1]->get_status() == 1 && (*board)[4]->get_status() == 1 && (*board)[7]->get_status() == 1)     //2nd column
        check = true;
    else if ((*board)[2]->get_status() == 1 && (*board)[5]->get_status() == 1 && (*board)[8]->get_status() == 1)     //3rd column
        check = true;
    else if ((*board)[0]->get_status() == 1 && (*board)[4]->get_status() == 1 && (*board)[8]->get_status() == 1)     //left diagonal
        check = true;
    else if ((*board)[2]->get_status() == 1 && (*board)[4]->get_status() == 1 && (*board)[6]->get_status() == 1)     //right diagonal
        check = true;
    else
        check = false;		// player1 has not won yet

    return check;
}

bool Game::computer_win()
{
    bool check;            //create bool

    if ((*board)[0]->get_status() == 2 && (*board)[1]->get_status() == 2 && (*board)[2]->get_status() == 2)          //1st row
        check = true;
    else if ((*board)[3]->get_status() == 2 && (*board)[4]->get_status() == 2 && (*board)[5]->get_status() == 2)     //2nd row
        check = true;
    else if ((*board)[6]->get_status() == 2 && (*board)[7]->get_status() == 2 && (*board)[8]->get_status() == 2)     //3rd row
        check = true;
    else if ((*board)[0]->get_status() == 2 && (*board)[3]->get_status() == 2 && (*board)[6]->get_status() == 2)     //1st column
        check = true;
    else if ((*board)[1]->get_status() == 2 && (*board)[4]->get_status() == 2 && (*board)[7]->get_status() == 2)     //2nd column
        check = true;
    else if ((*board)[2]->get_status() == 2 && (*board)[5]->get_status() == 2 && (*board)[8]->get_status() == 2)     //3rd column
        check = true;
    else if ((*board)[0]->get_status() == 2 && (*board)[4]->get_status() == 2 && (*board)[8]->get_status() == 2)     //left diagonal
        check = true;
    else if ((*board)[2]->get_status() == 2 && (*board)[4]->get_status() == 2 && (*board)[6]->get_status() == 2)     //right diagonal
        check = true;
    else
        check = false;		// computer has not won yet

    return check;
}

/*
 * The function get_counter() resets turn_counter every time, and then recounts the numner of box objects that
 * have been used, but checking their get_turn_used to see if turns_used is true or false.
 * @param: N/A
 * @return: N/A
*/
int vec::get_counter()
{
    turns_counter = 0;          //reset
    for (int i=0; i<10; i++)        //check all 9 box objects in vector
    {
        if(my_vec[i]->get_status() == 1 || my_vec[i]->get_status() == 2)       //if box has been used
            turns_counter++;                        //increment int turns_counter
    }
    return turns_counter;           //return int value with number of box objects used
}


/*
 * This is what I actually want the slot function to do in the future.
 * You can see that I need access to the vector<*box> board to check the positions of each used box and play the computer's turn.
 */

void vec::computer_play()
{

    if (get_counter() < 9)
    {
        for (int i = 0; i < 3; i++)
        {
            if (my_vec[3*i]->get_status() == 1 && my_vec[3*i+1]->get_status() == 1 && my_vec[3*i+2]->get_status() == 0)         //XXO horizontal
            {
                my_vec[3*i+2]->setText("O");
                my_vec[3*i+2]->setStyleSheet("font: bold; background-color: red;");
                my_vec[3*i+2]->set_status(2);
                return;
            }
            else if (my_vec[3*i]->get_status() == 0 && my_vec[3*i+1]->get_status() == 1 && my_vec[3*i+2]->get_status() == 1)    //OXX
            {
                my_vec[3*i]->setText("O");
                my_vec[3*i]->setStyleSheet("font: bold; background-color: red;");
                my_vec[3*i]->set_status(2);
                return;
            }
            else if (my_vec[3*i]->get_status() == 1 && my_vec[3*i+1]->get_status() == 0 && my_vec[3*i+2]->get_status() == 1)    //XOX
            {
                my_vec[3*i+1]->setText("O");
                my_vec[3*i+1]->setStyleSheet("font: bold; background-color: red;");
                my_vec[3*i+1]->set_status(2);
                return;
            }

            else if (my_vec[i]->get_status() == 1 && my_vec[i+3]->get_status() == 1 && my_vec[i+6]->get_status() == 0)      //XXO vertical
            {
                my_vec[i+6]->setText("O");
                my_vec[i+6]->setStyleSheet("font: bold; background-color: red;");
                my_vec[i+6]->set_status(2);
                return;
            }
            else if (my_vec[i]->get_status() == 0 && my_vec[i+3]->get_status() == 1 && my_vec[i+6]->get_status() == 1)      //OXX
            {
                my_vec[i]->setText("O");
                my_vec[i]->setStyleSheet("font: bold; background-color: red;");
                my_vec[i]->set_status(2);
                return;
            }
            else if (my_vec[i]->get_status() == 1 && my_vec[i+3]->get_status() == 0 && my_vec[i+6]->get_status() == 1)      //XOX
            {
                my_vec[i+3]->setText("O");
                my_vec[i+3]->setStyleSheet("font: bold; background-color: red;");
                my_vec[i+3]->set_status(2);
                return;
            }

        }

        // might need fix to else if

        if (my_vec[0]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[8]->get_status() == 0)         //left diagonal XXO
        {
            my_vec[8]->setText("O");
            my_vec[8]->setStyleSheet("font: bold; background-color: red;");
            my_vec[8]->set_status(2);
            return;
        }
        else if (my_vec[0]->get_status() == 0  && my_vec[4]->get_status() == 1 && my_vec[8]->get_status() == 1)   //OXX
        {
            my_vec[0]->setText("O");
            my_vec[0]->setStyleSheet("font: bold; background-color: red;");
            my_vec[0]->set_status(2);
            return;
        }
        else if (my_vec[0]->get_status() == 1 && my_vec[4]->get_status() == 0 && my_vec[8]->get_status() == 1)    //XOX
        {
            my_vec[4]->setText("O");
            my_vec[4]->setStyleSheet("font: bold; background-color: red;");
            my_vec[4]->set_status(2);
            return;
        }
        else if (my_vec[2]->get_status() == 1 && my_vec[4]->get_status() == 1 && my_vec[6]->get_status() == 0)    //right diagonal XXO
        {
            my_vec[6]->setText("O");
            my_vec[6]->setStyleSheet("font: bold; background-color: red;");
            my_vec[6]->set_status(2);
            return;
        }
        else if (my_vec[2]->get_status() == 0  && my_vec[4]->get_status() == 1 && my_vec[6]->get_status() == 1)   //OXX
        {
            my_vec[2]->setText("O");
            my_vec[2]->setStyleSheet("font: bold; background-color: red;");
            my_vec[2]->set_status(2);
            return;
        }
        else if (my_vec[2]->get_status() == 1 && my_vec[4]->get_status() == 0 && my_vec[6]->get_status() == 1)    //XOX
        {
            my_vec[4]->setText("O");
            my_vec[4]->setStyleSheet("font: bold; background-color: red;");
            my_vec[4]->set_status(2);
            return;
        }
        else
        {
            int rand, rand_index;
            do
            {
                rand = (std::rand() % 9);
                rand_index = abs(rand);
            } while(my_vec[rand_index]->get_status() != 0);

            my_vec[rand_index]->setText("O");
            my_vec[rand_index]->setStyleSheet("font: bold; background-color: red;");
            my_vec[rand_index]->set_status(2);
            return;
        }
    }
}
