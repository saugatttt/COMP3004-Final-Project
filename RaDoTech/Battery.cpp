#include "Battery.h"
#include <QMessageBox>
#include <QPushButton>

Battery::Battery(QProgressBar* progressBar) : QObject(nullptr), batteryLevel(100), progressBar(progressBar)
{
    progressBar->setRange(0, 100);
    progressBar->setValue(batteryLevel);
}

Battery::~Battery(){

}


int Battery::getBatteryLevel()
{
    return batteryLevel;
}

void Battery::chargeBattery()
{
    batteryLevel = 100;

    progressBar->setValue(batteryLevel);
    progressBar->setStyleSheet("");
}

void Battery::decreaseBatteryLevel()
{
    if (batteryLevel > 0) {
        batteryLevel -= 2;
        if(batteryLevel < 0){
            batteryLevel = 0;
        }
        progressBar->setValue(batteryLevel);

        if (batteryLevel <= 20) {
            progressBar->setStyleSheet("QProgressBar::chunk { background-color: red; }");
        }
    }
    else{
        if(batteryLevel < 0){
            batteryLevel = 0;
        }
        showLowBatteryWarning();
    }

}

void Battery::showLowBatteryWarning() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Battery is low! Please recharge to continue.");
    QPushButton* rechargeButton = msgBox.addButton("Recharge", QMessageBox::AcceptRole);
    msgBox.addButton("Don't charge", QMessageBox::RejectRole);

    msgBox.exec();

    if (msgBox.clickedButton()->text() == rechargeButton->text()) {
        chargeBattery();
    }
    else {
        msgBox.close();
    }
}
