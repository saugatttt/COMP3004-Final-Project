#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UserProfileManager.h"
#include "createprofiledialog.h"
#include "updateprofiledialog.h"
#include "selectprofiledialog.h"
#include "deleteprofiledialog.h"
#include "DataGenerator.h"
#include <random>
#include "scanwindow.h"
#include "RadoTechDevice.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createUserProfile();
    void selectUserProfile();
    void updateUserProfile();
    void deleteUserProfile();

signals:
    void userChanged();
    void userListChanged();


private slots:
    void onUserChanged();
    void onUserListChanged();
    void onStartScanButtonClicked();


private:
    UserProfileManager* manager;
    RadoTechDevice* device;
    UserProfile* currentUser = nullptr;

    CreateProfileDialog createProfileDialog;
    UpdateProfileDialog updateProfileDialog;
    SelectProfileDialog selectProfileDialog;
    DeleteProfileDialog deleteProfileDialog;

    Ui::MainWindow *ui;
};




#endif // MAINWINDOW_H
