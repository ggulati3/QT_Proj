#include <QApplication>
#include "jumper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Jumper game;
    game.setWindowTitle("Jumper");
    game.show();

    return a.exec();
}
