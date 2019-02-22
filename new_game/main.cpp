#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>
#include "door.h"
#include "doorpage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();               //show main window

    return a.exec();
}
