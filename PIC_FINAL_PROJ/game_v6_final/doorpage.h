
#ifndef DOORPAGE_H
#define DOORPAGE_H
#include "door.h"
#include <QGridLayout>

/* class that is a widget containing a layout, 3 doors, and 3 buttons; a page of doors, and the main screen of the app
 * */
class doorPage : public QWidget
{
public:
    doorPage(); //default creates a page of doors
    QGridLayout* layout = new QGridLayout;
    QPushButton* button = new QPushButton();
    QPushButton* button_2 = new QPushButton();
    QPushButton* button_3 = new QPushButton();
    door* d_1 = new door;
    door* d_2 = new door;
    door* d_3 = new door;
    ~doorPage();
};

#endif // DOORPAGE_H
