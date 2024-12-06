#ifndef HEALTHDATA_H
#define HEALTHDATA_H

#include "Scan.h"

class HealthData {

private:
    QList<Scan*> scans;

public:
    HealthData();
    ~HealthData();

    void addScan(Scan* scan);
    const QList<Scan*>& getScans() const;
};

#endif
