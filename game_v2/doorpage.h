
#ifndef DOORPAGE_H
#define DOORPAGE_H
#include "door.h"
#include <QGridLayout>
//#include "mainwindow.h"
class doorPage : public QWidget
{
public:
    doorPage(); //default constructor
    QPushButton* button = new QPushButton("Enter");
    door* d_1 = new door;
    door* d_2 = new door;
    door* d_3 = new door;
};

#endif // DOORPAGE_H
