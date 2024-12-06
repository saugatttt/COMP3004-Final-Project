#include "DataProcessor.h"

DataProcessor::DataProcessor()
{
}

Scan* DataProcessor::createScan(QList<int> data){
    QDate date = QDate::currentDate();

    QList<HealthStatus> healthLevels;

    for(int i = 0; i<24; i++){
        //deterine body part
        std::string num, letter;
        if(i < 12){
            letter = "H";
            num = std::to_string(i/2 + 1);
        }
        else {
            letter = "F";
            num = std::to_string((i-12)/2 + 1);
        }
        std::string bodyPart = letter + num;
        std::pair<int, int> threshold = getThresholds(bodyPart);

        //append HealthStatus to health level collection
        if(data.at(i) < threshold.first)
            healthLevels.append(low);
        else if(data.at(i) > threshold.second)
            healthLevels.append(high);
        else
            healthLevels.append(normal);
    }

    Scan* scan = new Scan(date, data, healthLevels);
    return scan;
}

//helper method
std::pair<int, int> DataProcessor::getThresholds(const std::string& bodyPart){
    if (bodyPart == "H1") return {H1_low, H1_high};
    if (bodyPart == "H2") return {H2_low, H2_high};
    if (bodyPart == "H3") return {H3_low, H3_high};
    if (bodyPart == "H4") return {H4_low, H4_high};
    if (bodyPart == "H5") return {H5_low, H5_high};
    if (bodyPart == "H6") return {H6_low, H6_high};
    if (bodyPart == "F1") return {F1_low, F1_high};
    if (bodyPart == "F2") return {F2_low, F2_high};
    if (bodyPart == "F3") return {F3_low, F3_high};
    if (bodyPart == "F4") return {F4_low, F4_high};
    if (bodyPart == "F5") return {F5_low, F5_high};
    if (bodyPart == "F6") return {F6_low, F6_high};

    throw std::invalid_argument("Invalid body part: " + bodyPart);
}
