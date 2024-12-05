#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_createprofiledialog.h"
#include "ui_selectprofiledialog.h"
#include "ui_updateprofiledialog.h"
#include "ui_deleteprofiledialog.h"
#include "scanwindow.h"
#include <QEventLoop>
#include <QTimer>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    manager = new UserProfileManager("./users.json", nullptr);
      
    batteryObj = new battery(ui->progressBar);
    connect(ui->chargeButton, SIGNAL(released()), this, SLOT (chargeButtonClicked()));

    connect(this, &MainWindow::userChanged, this, &MainWindow::onUserChanged);
    connect(this, &MainWindow::userListChanged, this, &MainWindow::onUserListChanged);

    emit userChanged();
    emit userListChanged();

    // create an initProfileDialogs method for this
    createProfileDialog.setModal(true);
    selectProfileDialog.setModal(true);
    updateProfileDialog.setModal(true);
    deleteProfileDialog.setModal(true);

    connect(ui->createProfileButton, &QPushButton::clicked , &createProfileDialog, &CreateProfileDialog::exec);
    connect(ui->selectProfileButton, &QPushButton::clicked , &selectProfileDialog, &SelectProfileDialog::exec);
    connect(ui->updateProfileButton, &QPushButton::clicked , &updateProfileDialog, &UpdateProfileDialog::exec);
    connect(ui->deleteProfileButton, &QPushButton::clicked , &deleteProfileDialog, &DeleteProfileDialog::exec);

    connect(createProfileDialog.getUi()->confirmProfileButton, &QPushButton::clicked, this, &MainWindow::createUserProfile);
    connect(selectProfileDialog.getUi()->confirmProfileButton, &QPushButton::clicked, this, &MainWindow::selectUserProfile);
    connect(updateProfileDialog.getUi()->confirmProfileButton, &QPushButton::clicked, this, &MainWindow::updateUserProfile);
    connect(deleteProfileDialog.getUi()->confirmProfileButton, &QPushButton::clicked, this, &MainWindow::deleteUserProfile);

    connect(createProfileDialog.getUi()->cancelProfileButton, &QPushButton::clicked, &createProfileDialog, &CreateProfileDialog::close);
    connect(selectProfileDialog.getUi()->cancelProfileButton, &QPushButton::clicked, &selectProfileDialog, &SelectProfileDialog::close);
    connect(updateProfileDialog.getUi()->cancelProfileButton, &QPushButton::clicked, &updateProfileDialog, &UpdateProfileDialog::close);
    connect(deleteProfileDialog.getUi()->cancelProfileButton, &QPushButton::clicked, &deleteProfileDialog, &DeleteProfileDialog::close);

}

void MainWindow::onUserChanged() {
    if (currentUser == nullptr){
        ui->tabWidget->setTabEnabled(1, false);
        ui->tabWidget->setTabEnabled(2, false);
        ui->tabWidget->setTabEnabled(3, false);
        ui->tabWidget->setTabEnabled(4, false);
        return;
    }
    QList<QWidget*> list = ui->tabWidget->findChildren<QWidget*>() ;
    ui->tabWidget->setTabEnabled(1, true);
    ui->tabWidget->setTabEnabled(2, true);
    ui->tabWidget->setTabEnabled(3, true);
    ui->tabWidget->setTabEnabled(4, true);
    return;

}

void MainWindow::onUserListChanged() {
    Ui::SelectProfileDialog* selectProfileUi = selectProfileDialog.getUi();
    Ui::DeleteProfileDialog* deleteProfileUi = deleteProfileDialog.getUi();

    if (selectProfileUi->userListView->model() != nullptr){
        delete selectProfileUi->userListView->model();
        delete deleteProfileUi->userListView->model();
    }

    QList<UserProfile*> userList = manager->getUsers();
    QStringList userAddresses = QStringList();
    for (UserProfile* user : userList) {
        userAddresses.append(user->getEmail());
    }
    QStringListModel* listModel = new QStringListModel(userAddresses, selectProfileUi->userListView);

    selectProfileUi->userListView->setModel(listModel);
    deleteProfileUi->userListView->setModel(listModel);
}

void MainWindow::createUserProfile() {

    Ui::CreateProfileDialog* createProfileUi = createProfileDialog.getUi();
    createProfileUi->confirmProfileButton->setEnabled(false);

    if (manager->createUserProfile(createProfileUi->firstNameCreateProfileEdit->text(),
                                   createProfileUi->lastNameCreateProfileEdit->text(),
                                   createProfileUi->emailCreateProfileEdit->text(),
                                   createProfileUi->genderCreateProfileEdit->text(),
                                   createProfileUi->ageCreateProfileEdit->text().toInt(),
                                   createProfileUi->weightCreateProfileEdit->text().toFloat(),
                                   createProfileUi->heightCreateProfileEdit->text().toFloat())){
        createProfileDialog.close();
        createProfileUi->firstNameCreateProfileEdit->setText("");
        createProfileUi->lastNameCreateProfileEdit->setText("");
        createProfileUi->emailCreateProfileEdit->setText("");
        createProfileUi->genderCreateProfileEdit->setText("");
        createProfileUi->ageCreateProfileEdit->setText("");
        createProfileUi->weightCreateProfileEdit->setText("");
        createProfileUi->heightCreateProfileEdit->setText("");
        emit userListChanged();
    }
    else {
        createProfileUi->emailCreateProfileEdit->setText("");
        createProfileUi->invalidEmailLabel->setText("Duplicate email detected. Please use another email.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        createProfileUi->invalidEmailLabel->setText("");
    }
    createProfileUi->confirmProfileButton->setEnabled(true);
}

void MainWindow::selectUserProfile() {
    Ui::SelectProfileDialog* selectProfileUi = selectProfileDialog.getUi();
    selectProfileUi->confirmProfileButton->setEnabled(false);

    QList<UserProfile*> userList = manager->getUsers();

    int selectedIndex = selectProfileUi->userListView->currentIndex().row();
    if (selectedIndex == -1){
        selectProfileUi->invalidSelectionLabel->setText("No user selected. Please select a user.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        selectProfileUi->invalidSelectionLabel->setText("");
        selectProfileUi->confirmProfileButton->setEnabled(true);
        return;
    }
    currentUser = userList[selectedIndex];
    emit userChanged();
    selectProfileDialog.close();
    selectProfileUi->confirmProfileButton->setEnabled(true);
}

void MainWindow::updateUserProfile() {
    Ui::UpdateProfileDialog* updateProfileUi = updateProfileDialog.getUi();
    updateProfileUi->confirmProfileButton->setEnabled(false);

    if (manager->updateUserProfile(updateProfileUi->firstNameUpdateProfileEdit->text(),
                                       updateProfileUi->lastNameUpdateProfileEdit->text(),
                                       updateProfileUi->emailUpdateProfileEdit->text(),
                                       updateProfileUi->genderUpdateProfileEdit->text(),
                                       updateProfileUi->ageUpdateProfileEdit->text().toInt(),
                                       updateProfileUi->weightUpdateProfileEdit->text().toFloat(),
                                       updateProfileUi->heightUpdateProfileEdit->text().toFloat())){
            createProfileDialog.close();
            updateProfileUi->firstNameUpdateProfileEdit->setText("");
            updateProfileUi->lastNameUpdateProfileEdit->setText("");
            updateProfileUi->emailUpdateProfileEdit->setText("");
            updateProfileUi->genderUpdateProfileEdit->setText("");
            updateProfileUi->ageUpdateProfileEdit->setText("");
            updateProfileUi->weightUpdateProfileEdit->setText("");
            updateProfileUi->heightUpdateProfileEdit->setText("");
        }
        else {
            updateProfileUi->emailUpdateProfileEdit->setText("");
            updateProfileUi->invalidEmailLabel->setText("Email not found. Please use an appropriate email.");
            QEventLoop loop;
            QTimer::singleShot(3000, &loop, &QEventLoop::quit);
            loop.exec();
            updateProfileUi->invalidEmailLabel->setText("");
        }

    updateProfileDialog.close();
    updateProfileUi->confirmProfileButton->setEnabled(true);
}

void MainWindow::deleteUserProfile() {
    Ui::DeleteProfileDialog* deleteProfileUi = deleteProfileDialog.getUi();
    QList<UserProfile*> userList = manager->getUsers();

    int selectedIndex = deleteProfileUi->userListView->currentIndex().row();
    if (selectedIndex == -1){
        deleteProfileUi->invalidSelectionLabel->setText("No user selected. Please select a user.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        deleteProfileUi->invalidSelectionLabel->setText("");
        return;
    }
    if (currentUser == userList[selectedIndex]){
        currentUser = nullptr;
        emit userChanged();
    }
    manager->deleteUserProfile(userList[selectedIndex]->getEmail());
    deleteProfileDialog.close();
    emit userListChanged();
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

