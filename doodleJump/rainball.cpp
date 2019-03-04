#include "rainball.h"

rainBall::rainBall()
{
    QImage inputDrop("/Users/gauravgulati/desktop");

    drop = inputDrop.scaled(20,20, Qt::KeepAspectRatio);
}
