#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include "doorpage.h"
#include "game_one.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QWidget* secondWindow = new doorPage;
    QWidget* check = new game_one;
    QStackedWidget* stackWidget = new QStackedWidget;
    friend doorPage;
    int num_keys = 1;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
