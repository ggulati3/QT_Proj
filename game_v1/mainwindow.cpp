#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include "door.h"
#include "doorpage.h"
#include "namepage.h"
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
      ui->setupUi(this);
      QWidget* firstWindow = new NamePage;
      QWidget* secondWindow = new doorPage;
      QGridLayout* layout = new QGridLayout;

      layout->addWidget(secondWindow);
      layout->addWidget(firstWindow);
      this->setCentralWidget(secondWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
