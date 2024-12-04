#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new UserProfileManager("./users.json", nullptr);

    manager->createUserProfile("Rami", "Golea", "rami.golea@gmail.com", "Male", 20, 66, 173);
    manager->createUserProfile("Test", "hello", "hi@example.com", "Female", 25, 49, 160);

    manager->deleteUserProfile("hi@example.com");


}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

