#ifndef KEY_H
#define KEY_H
#include <QHBoxLayout>
#include <QLabel>
 /* class that creates a label with a picture of a key
  */
class key: public QLabel
{
public:
    key();//default constructor, creates key image
};

/* class that contains 3 instances of key and a horizontal layout
 */
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
