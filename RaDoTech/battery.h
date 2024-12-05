#ifndef BATTERY_H
#define BATTERY_H

#include <QProgressBar>

class battery {
public:
    battery(QProgressBar* progressBar);
    ~battery();

    int getBatteryLevel();
    void chargeBattery();
    void decreaseBatteryLevel();
    void showLowBatteryWarning();


private:
    int batteryLevel;
    QProgressBar* progressBar;
};

#endif // BATTERY_H
