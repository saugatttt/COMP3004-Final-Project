#ifndef BATTERY_H
#define BATTERY_H

#include <QProgressBar>

class Battery: public QObject {
    Q_OBJECT

public:
    Battery(QProgressBar* progressBar, QObject* parent = nullptr);
    ~Battery();

    int getBatteryLevel();
    void chargeBattery();
    void decreaseBatteryLevel();
    void showLowBatteryWarning();

signals:
    void didNotCharge();

private:
    int batteryLevel;
    QProgressBar* progressBar;
};

#endif // BATTERY_H
