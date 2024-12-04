#include "Scan.h"

Scan::Scan(QDate& date)
    : date(date)
{
}

QDate Scan::getDate() const { return date; }
