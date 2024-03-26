#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new ShapeMediatorWidget(this));
}

MainWindow::~MainWindow()
{
}

