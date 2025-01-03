#ifndef SCAN_H
#define SCAN_H

#include <QString>
#include <QDate>

enum HealthStatus{ normal, high, low };

class Scan {

private:
    QDateTime dateTime;

    // store 24 values in the following order:
    // H1(left), H1(right), H2(left), H2(right), [...], F5(left), F5(right), F6(left), F6(right)
    QList<int> measurements;    //raw data
    QList<HealthStatus> healthLevels;
public:
    Scan(QDateTime &dateTime, QList<int> measurements, QList<HealthStatus>);

    QDateTime getDateTime() const;
    QList<int> getMeasurements() const;
    QList<HealthStatus> getHealthLevels() const;

};

#endif
