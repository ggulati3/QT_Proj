#ifndef FINALPAGE_H
#define FINALPAGE_H
#include <QLabel>
#include <QGridLayout>

/* class of the final win screen- after you win all 3 minigames
 * */
class finalpage: public QLabel
{
public:
    finalpage();//default constructor
    QGridLayout* layout = new QGridLayout;
};

#endif // FINALPAGE_H
