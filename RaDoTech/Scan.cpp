#include "Scan.h"

Scan::Scan(QDate& date, QList<int> measurements, QList<HealthStatus> healthLevels)
    : date(date),
      measurements(measurements),
      healthLevels(healthLevels)
{
}

QDate Scan::getDate() const { return date; }

QList<int> Scan::getMeasurements() const {return measurements;}

QList<HealthStatus> Scan::getHealthLevels() const {return healthLevels;}
