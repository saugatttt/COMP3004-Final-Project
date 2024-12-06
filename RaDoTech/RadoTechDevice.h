#ifndef RADOTECHDEVICE_H
#define RADOTECHDEVICE_H

#include "Battery.h"
#include "DataGenerator.h"

#define GLOBAL_RAND_RANGE 10

class RadoTechDevice {

private:

    Battery* batteryObj;
    DataGenerator* generator;
    QList<int>* list;
    int globalDeviation;

public:
    RadoTechDevice(QProgressBar* bar);
    ~RadoTechDevice();

    int generateMeasurement(int index);

    Battery* getBattery();



};

#endif // RADOTECHDEVICE_H
