#include "RadoTechDevice.h"
#include <random>
#include <QMessageBox>

RadoTechDevice::RadoTechDevice(QProgressBar* bar) :
    batteryObj(new Battery(bar)),
    generator(new DataGenerator())
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0 - GLOBAL_RAND_RANGE, GLOBAL_RAND_RANGE);
    globalDeviation = dis(gen);  //will apply to all 24 measurements
}

RadoTechDevice::~RadoTechDevice() {
    delete batteryObj;
    delete generator;
}

Battery* RadoTechDevice::getBattery() {
    return batteryObj;
}

int RadoTechDevice::generateMeasurement(int index) {
    return generator->generateMeasurement(index, globalDeviation);
}




