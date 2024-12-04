#include "HealthData.h"

void HealthData::addScan(Scan* scan) {
    m_scans.push_back(scan);
}

const QList<Scan*>& HealthData::scans() const {
    return m_scans;
}
