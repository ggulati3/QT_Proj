#include <QApplication>
#include "spacerunner.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    spaceRunner game;
    game.show();

    return a.exec();
}
