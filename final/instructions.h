#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class instruc : public QWidget {
public:
    instruc();
    QPushButton* start = new QPushButton("Start");
    QPushButton* back = new QPushButton("Back");
    QGridLayout * layout = new QGridLayout;
    QLabel* instruction;
};


class instruction_game1 : public QWidget {
public:
    instruction_game1();
    QPushButton* start = new QPushButton("Start");
    QPushButton* back = new QPushButton("Back");
    QGridLayout * layout = new QGridLayout;
    QLabel* instruction;
};

class instruction_game2 : public QWidget {
public:
    instruction_game2();
    QPushButton* start = new QPushButton("Start");
    QPushButton* back = new QPushButton("Back");
    QGridLayout * layout = new QGridLayout;
    QLabel* instruction;
};

class instruction_game3 : public QWidget {
public:
    instruction_game3();
    QPushButton* start = new QPushButton("Start");
    QPushButton* back = new QPushButton("Back");
    QGridLayout * layout = new QGridLayout;
    QLabel* instruction;
};

#endif // INSTRUCTIONS_H
