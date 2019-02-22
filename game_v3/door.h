#ifndef DOOR_H
#define DOOR_H

#include <QWidget>
#include <QPushButton>
#include <QLayout>
#include <QLabel>

class door : public QLabel
{
    Q_OBJECT
    public:
        door();    //creates door image

    public slots:
        void open_door();    //changes image from closed door to open door
};

#endif // DOOR_H
