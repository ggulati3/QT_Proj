#ifndef KEY_H
#define KEY_H
#include <QHBoxLayout>
#include <QLabel>

class key: public QLabel
{
public:
    key();//default constructor, creates key image
};

class keys: public QWidget
{
public:
    keys();
    key* key_1 = new key;
    key* key_2 = new key;
    key* key_3 = new key;
    QHBoxLayout* layout = new QHBoxLayout;

};

#endif // KEY_H
