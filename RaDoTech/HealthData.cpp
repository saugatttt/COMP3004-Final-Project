#include "HealthData.h"

HealthData::HealthData() {
}

void HealthData::addScan(Scan* scan) {
    scans.push_back(scan);
}

const QList<Scan*>& HealthData::getScans() const {
    return scans;
}
