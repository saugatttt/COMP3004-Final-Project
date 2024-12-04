#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include "Scan.h"

class HealthData {

private:
    QList<Scan*> m_scans;

public:
    void addScan(Scan* scan);
    const QList<Scan*>& scans() const;
};

#endif
