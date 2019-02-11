#include "mainwindow.h"
#include <QApplication>
#include <QStackedWidget>
#include "door.h"
#include "doorpage.h"
#include "game_one.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /*

     stackWidget->addWidget(secondWindow); // doors - index 0
     stackWidget->addWidget(check); //hello - index 1

     stackWidget->setCurrentIndex(1);

     //QObject::connect(button, SIGNAL(clicked()),d_1, SLOT(stackWidget->setCurrentWidget(1)));

     w.setCentralWidget(stackWidget);
*/

    return a.exec();
}
