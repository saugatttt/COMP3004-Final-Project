#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * Rami's old test stuff
    manager = new UserProfileManager("./users.json", nullptr);

    manager->createUserProfile("Rami", "Golea", "rami.golea@gmail.com", "Male", 20, 66, 173);
    manager->createUserProfile("Test", "hello", "hi@example.com", "Female", 25, 49, 160);

    manager->deleteUserProfile("hi@example.com");
    */

}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}

void MainWindow::on_startScanButton_clicked()   //todo: decide where this happens and establish the call sequence
{
    QList<int> *list = new QList<int>();
    ScanWindow* scanWindow = new ScanWindow(nullptr, list);     //todo: make this a field of the mainwindow object. This current setup was for very basic testing.
    scanWindow->setModal(true);
    scanWindow->exec();
    qDebug()<<list->size();
    list->clear();
}

