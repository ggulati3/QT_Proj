#include "instructions.h"

instruction_game1::instruction_game1() {
    instruction = new QLabel("Instructions: Welcome to Space Runner! \n"
                             "The objective is to get the red circle to the other side.\n"
                             "In order to win the blue circle must touch the blue rectangle\n"
                             "on the opposite side. You can use the arrow keys to move left,\n"
                             "right, up, and down. But be careful! If you touch any of the \n"
                             "yellow dots you lose. Good Luck!");
    QFont f("Courier", 30, QFont::DemiBold);
    instruction->setFont(f);
    instruction->setStyleSheet("color: white");

    start->setFont(f);
    back->setFont(f);

    layout->addWidget(instruction);
    layout->addWidget(start);
    layout->addWidget(back);

    this->setLayout(layout);
}

instruction_game2::instruction_game2() {
    instruction = new QLabel("Instructions: Welcome to Tic Tac Toe! \n"
                             "The object if to get three in a row (horizontally, vertically, \n"
                             "or diagonally). Be warned after every turn, the the very smart \n"
                             "computer will place its item on the board in the opposite color.\n"
                             "You lose if the computer wins or ties with you.\n"
                             "Good Luck!");
    QFont f("Courier", 30, QFont::DemiBold);
    instruction->setFont(f);
    instruction->setStyleSheet("color: white");

    start->setFont(f);
    back->setFont(f);

    layout->addWidget(instruction);
    layout->addWidget(start);
    layout->addWidget(back);

    this->setLayout(layout);
}

instruction_game3::instruction_game3() {
    instruction = new QLabel("Instructions: Welcome to Alien Invasion! \n"
                             "You control the ship and your objective is to kill 20 aliens.\n"
                             "You can move left and right via the left and right arrow keys.\n"
                             "To shoot your missiles just hit the space bar. You will loose \n"
                             "the game if an alien hits your ship before you can kill 20 aliens. \n"
                             "Good Luck!");
    QFont f("Courier", 30, QFont::DemiBold);
    instruction->setFont(f);
    instruction->setStyleSheet("color: white");

    start->setFont(f);
    back->setFont(f);

    layout->addWidget(instruction);
    layout->addWidget(start);
    layout->addWidget(back);

    this->setLayout(layout);
}
