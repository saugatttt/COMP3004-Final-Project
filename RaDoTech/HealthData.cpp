#include "HealthData.h"

HealthData::HealthData() {
}

HealthData::~HealthData() {
    for (Scan* scan : scans){
        delete scan;
    }
}

void HealthData::addScan(Scan* scan) {
    scans.push_back(scan);
}

const QList<Scan*>& HealthData::getScans() const {
    return scans;
}
