#include "DataGenerator.h"
#include <string>
#include <QDebug>
#include <random>

DataGenerator::DataGenerator():
    averageResults({H1, H2, H3, H4, H5, H6, F1, F2, F3, F4, F5, F6})
{
}

/*
    index is an int from 0-23 to specify which body part we are scanning
    deviation is the base randomizer's computed difference, which will affect the average before we apply second randomizer
*/
int DataGenerator::generateMeasurement(int index, int deviation){
    int modifiedAverage = averageResults.at(index/2) + deviation;

    int min = modifiedAverage - INDIVIDUAL_RAND_RANGE;
    int max = modifiedAverage + INDIVIDUAL_RAND_RANGE;

    qDebug()<< "min: " << min;
    qDebug()<< "max: " << max;

    //apply individual randomizer
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(min, max);
    int result = dis(gen);

    return result;
}



