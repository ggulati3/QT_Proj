#ifndef FINALPAGE_H
#define FINALPAGE_H
#include <QLabel>
#include <QGridLayout>
class finalpage: public QLabel
{
public:
    finalpage();//default constructor - creates a trophy image
    QGridLayout* layout = new QGridLayout;
};

#endif // FINALPAGE_H
