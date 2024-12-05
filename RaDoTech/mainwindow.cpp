#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    batteryObj = new battery(ui->progressBar);
    connect(ui->chargeButton, SIGNAL(released()), this, SLOT (chargeButtonClicked()));

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

    ScanWindow* scanWindow = new ScanWindow(nullptr, list,batteryObj);
    scanWindow->setModal(true);
    scanWindow->exec();
    delete scanWindow;
    qDebug()<<list->size();
    list->clear();
    delete list;
}


void MainWindow::chargeButtonClicked() {
    batteryObj->chargeBattery();
}

