
#ifndef DOORPAGE_H
#define DOORPAGE_H
#include "door.h"
#include <QGridLayout>

class doorPage : public QWidget
{
public:
    doorPage(); //default constructor
    QGridLayout* layout = new QGridLayout;
    QPushButton* button = new QPushButton("Enter");
    QPushButton* button_2 = new QPushButton("Enter");
    QPushButton* button_3 = new QPushButton("Enter");
    door* d_1 = new door;
    door* d_2 = new door;
    door* d_3 = new door;
    ~doorPage();
};

#endif // DOORPAGE_H
