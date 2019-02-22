#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include <QStatusBar>
#include "doorpage.h"
#include "gameone.h"
#include "gametwo.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    doorPage* firstpage = new doorPage;               //main screen
    gameone* secondpage = new gameone;
    gametwo* thirdpage = new gametwo;
    QStackedWidget* stackWidget = new QStackedWidget;   //stacked widget for main screen and games
    friend doorPage;
    int num_keys = 1;       //key counter for whole program
    QStatusBar* sbar = new QStatusBar;
    void connect_buttons();
public slots:
    void go_to_page_2();
    void go_to_main();
    void win_gameone();
    void go_to_page_3();
    void win_gametwo();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
