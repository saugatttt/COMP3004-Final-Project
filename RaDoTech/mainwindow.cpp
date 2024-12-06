#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_createprofiledialog.h"
#include "ui_selectprofiledialog.h"
#include "ui_updateprofiledialog.h"
#include "ui_deleteprofiledialog.h"
#include "ui_scanwindow.h"
#include <QEventLoop>
#include <QTimer>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new UserProfileManager("./users.json", nullptr);
    device = new RadoTechDevice(ui->progressBar);
    connect(ui->chargeButton, &QPushButton::clicked, device->getBattery(), &Battery::chargeBattery);

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

    connect(ui->startScanButton, &QPushButton::clicked, this, &MainWindow::onStartScanButtonClicked);
}

MainWindow::~MainWindow()
{
    delete manager;
    delete ui;
}


void MainWindow::onUserChanged() {
    if (currentUser == nullptr){
        ui->loggedInStatus->setText("Logged out");
        ui->tabWidget->setTabEnabled(1, false);
        ui->tabWidget->setTabEnabled(2, false);
        ui->tabWidget->setTabEnabled(3, false);
        ui->tabWidget->setTabEnabled(4, false);
        return;
    }
    QList<QWidget*> list = ui->tabWidget->findChildren<QWidget*>() ;
    ui->loggedInStatus->setText("Logged in as: " + currentUser->getEmail());
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

    if (createProfileUi->firstNameCreateProfileEdit->text() == ""
            || createProfileUi->lastNameCreateProfileEdit->text() == ""
            || createProfileUi->emailCreateProfileEdit->text() == ""
            || createProfileUi->genderCreateProfileEdit->text() == ""
            || createProfileUi->ageCreateProfileEdit->text() == ""
            || createProfileUi->weightCreateProfileEdit->text() == ""
            || createProfileUi->heightCreateProfileEdit->text() == ""
    ){
        createProfileUi->invalidEntryLabel->setText("Empty field detected. Please fill out every field.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        createProfileUi->invalidEntryLabel->setText("");
    }
    else if (manager->createUserProfile(createProfileUi->firstNameCreateProfileEdit->text(),
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
        createProfileUi->invalidEntryLabel->setText("Duplicate email detected. Please use another email.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        createProfileUi->invalidEntryLabel->setText("");
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

    if (updateProfileUi->firstNameUpdateProfileEdit->text() == ""
            || updateProfileUi->lastNameUpdateProfileEdit->text() == ""
            || updateProfileUi->emailUpdateProfileEdit->text() == ""
            || updateProfileUi->genderUpdateProfileEdit->text() == ""
            || updateProfileUi->ageUpdateProfileEdit->text() == ""
            || updateProfileUi->weightUpdateProfileEdit->text() == ""
            || updateProfileUi->heightUpdateProfileEdit->text() == ""
    ){
        updateProfileUi->invalidEntryLabel->setText("Empty field detected. Please fill out every field.");
        QEventLoop loop;
        QTimer::singleShot(3000, &loop, &QEventLoop::quit);
        loop.exec();
        updateProfileUi->invalidEntryLabel->setText("");
    }
    else if (manager->updateUserProfile(updateProfileUi->firstNameUpdateProfileEdit->text(),
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
            updateProfileUi->invalidEntryLabel->setText("Email not found. Please use an appropriate email.");
            QEventLoop loop;
            QTimer::singleShot(3000, &loop, &QEventLoop::quit);
            loop.exec();
            updateProfileUi->invalidEntryLabel->setText("");
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


void MainWindow::onStartScanButtonClicked()
{
    if(!ui->jewelryToggle->isChecked() || !ui->moisturizedToggle->isChecked()){
        QMessageBox msgError;
        msgError.setText("You must remove your jewelry and moisturize your skin before starting your scan");
        msgError.setIcon(QMessageBox::Warning);
        msgError.exec();
        return;
    }

    QList<int> *list = new QList<int>();
    ScanWindow* scanWindow = new ScanWindow(nullptr, list, device);
    scanWindow->setModal(true);
    scanWindow->exec();
    delete scanWindow;

    //basic testing of data processor, feel free to remove
    if(list->size() != 23){
        list->clear();
        delete list;
        return;
    }
    Scan* scan = DataProcessor::createScan(*list);
    QList<int> scanMeasurements = scan->getMeasurements();
    QList<HealthStatus> scanHealthLevels = scan->getHealthLevels();
    for(int value : scanMeasurements){
        qDebug() << value;
    }
    for(int i = 0; i<scanHealthLevels.size(); ++i){
        std::string healthLevelAsString;
        HealthStatus status = scanHealthLevels.at(i);

        if(status == normal)
            healthLevelAsString = "normal";
        else if(status == high)
            healthLevelAsString = "high";
        else
            healthLevelAsString = "low";

        qDebug() << QString::fromStdString(healthLevelAsString);
    }

    delete scan;
    list->clear();
    delete list;
}

