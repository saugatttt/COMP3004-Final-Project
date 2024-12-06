#include "Scan.h"

Scan::Scan(QDateTime& dateTime, QList<int> measurements, QList<HealthStatus> healthLevels)
    : dateTime(dateTime),
      measurements(measurements),
      healthLevels(healthLevels)
{
}

QDateTime Scan::getDateTime() const { return dateTime; }

QList<int> Scan::getMeasurements() const {return measurements;}

QList<HealthStatus> Scan::getHealthLevels() const {return healthLevels;}
