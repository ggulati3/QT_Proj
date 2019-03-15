#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
/* A base class for all the instructions pages; contains a standard start button, back button, font and layout
*/
class instructions: public QWidget{
public:
    instructions();
    QFont* f= new QFont("Courier", 30, QFont::DemiBold);
    QPushButton* start = new QPushButton("Start");
    QPushButton* back = new QPushButton("Back");
    QGridLayout * layout = new QGridLayout;
    ~instructions();
};

/* A class derived from base instructions class; contains an instruction label to add
*/
class instruc : public instructions {
public:
    instruc();
    QLabel* instruction;
};

/* A class derived from base instructions class; contains an instruction label to add
*/
class instruction_game1 : public instructions {
public:
    instruction_game1();
    QLabel* instruction;
};

/* A class derived from base instructions class; contains an instruction label to add
*/
class instruction_game2 : public instructions {
public:
    instruction_game2();
    QLabel* instruction;
};

/* A class derived from base instructions class; contains an instruction label to add
*/
class instruction_game3 : public instructions {
public:
    instruction_game3();
    QLabel* instruction;
};

#endif // INSTRUCTIONS_H
