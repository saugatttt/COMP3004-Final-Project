#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "Scan.h"

//values are taken from the chart in the project specs
enum Thresholds {
    H1_low = 58, H1_high = 82,
    H2_low = 52, H2_high = 78,
    H3_low = 43, H3_high = 63,
    H4_low = 53, H4_high = 77,
    H5_low = 60, H5_high = 90,
    H6_low = 61, H6_high = 89,
    F1_low = 48, F1_high = 70,
    F2_low = 40, F2_high = 58,
    F3_low = 45, F3_high = 65,
    F4_low = 45, F4_high = 65,
    F5_low = 40, F5_high = 56,
    F6_low = 43, F6_high = 63
};

class DataProcessor
{
private:
    static std::pair<int, int> getThresholds(const std::string& bodyPart);

public:
    DataProcessor();
    static Scan* createScan(QList<int> data);
};

#endif // DATAPROCESSOR_H
