#include "Scan.h"

Scan::Scan(QDate& date)
    : date(date)
{
}

QDate Scan::getDate() const { return date; }

QList<int> Scan::getMeasurements() const {return measurements;}
