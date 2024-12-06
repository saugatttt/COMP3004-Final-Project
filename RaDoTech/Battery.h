#ifndef BATTERY_H
#define BATTERY_H

#include <QProgressBar>

class Battery: public QObject {
public:
    Battery(QProgressBar* progressBar);
    ~Battery();

    int getBatteryLevel();
    void chargeBattery();
    void decreaseBatteryLevel();
    void showLowBatteryWarning();

private:
    int batteryLevel;
    QProgressBar* progressBar;
};

#endif // BATTERY_H
