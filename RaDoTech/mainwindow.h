#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UserProfileManager.h"
#include "DataGenerator.h"
#include <random>

#include "battery.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    UserProfileManager* manager;
    Ui::MainWindow *ui;
    battery *batteryObj;
private slots:
    void on_startScanButton_clicked();
    void chargeButtonClicked();

};




#endif // MAINWINDOW_H
