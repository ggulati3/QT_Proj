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
        door(QWidget *parent=0);
};

#endif // DOOR_H