#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#define INDIVIDUAL_RAND_RANGE 5

#include "Scan.h"

//average is defined as the midpoint of the acceptable range for each body part
enum AverageResults {H1=70, H2=65, H3=53, H4=65, H5=75, H6=75,
                     F1=59, F2=49, F3=55, F4=55, F5=48, F6=53};

class DataGenerator
{
private:
    const QList<int> averageResults;
public:
    DataGenerator();
    int generateMeasurement(int index, int deviation);
};

#endif // DATAGENERATOR_H
