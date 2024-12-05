#include "battery.h"
#include <QMessageBox>
#include <QPushButton>

battery::battery(QProgressBar* progressBar) :batteryLevel(100), progressBar(progressBar)
{
    progressBar->setRange(0, 100);
    progressBar->setValue(batteryLevel);
}


int battery::getBatteryLevel()
{
    return batteryLevel;
}

void battery::chargeBattery()
{
    batteryLevel = 100;

    progressBar->setValue(batteryLevel);
    progressBar->setStyleSheet("");
}

void battery::decreaseBatteryLevel()
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

void battery::showLowBatteryWarning() {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Battery is low! Please recharge to continue.");
    QPushButton* rechargeButton = msgBox.addButton("Recharge", QMessageBox::AcceptRole);
    QPushButton* cancelButton = msgBox.addButton("Don't charge", QMessageBox::RejectRole);

    msgBox.exec();

    if (msgBox.clickedButton()->text() == rechargeButton->text()) {
        chargeBattery();
    }
}



