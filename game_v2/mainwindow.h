#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include "doorpage.h"
//#include "game_one.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* secondWindow = new doorPage;               //main screen
    QStackedWidget* stackWidget = new QStackedWidget;   //stacked widget for main screen and games
    friend doorPage;
    int num_keys = 1;       //key counter for whole program

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
