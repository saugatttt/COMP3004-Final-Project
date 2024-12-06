#include "JsonPersistence.h"
#include "DataProcessor.h"
#include <QDebug>

JsonPersistence::JsonPersistence(const QString &filePath, QObject *parent)
    : QObject(parent), filePath(filePath)
{
    loadFromJson();
}

JsonPersistence::~JsonPersistence()
{
    saveToJson();
}

bool JsonPersistence::addUser(UserProfile* user)
{
    if (findIndex(user->getEmail()) != -1) {
        return false;
    }
    QJsonObject userJson = userProfileToJson(user);
    userData.append(userJson);
    return saveToJson();
}

bool JsonPersistence::updateUser(const QString& firstName, const QString& lastName, const QString& email, const QString& gender, int age, float weight, float height) {
    int index = findIndex(email);
    if (index == -1) {
        return false;
    }
    QJsonObject user = userData.takeAt(index).toObject();
    user["firstName"] = firstName;
    user["lastName"] = lastName;
    user["email"] = email;
    user["gender"] = gender;
    user["age"] = age;
    user["weight"] = weight;
    user["height"] = height;
    userData.insert(index, user);

    return saveToJson();
}

bool JsonPersistence::updateUser(const QString& email, Scan* scan) {
    int index = findIndex(email);
    if (index == -1) {
        return false;
    }
    QJsonObject user = userData.takeAt(index).toObject();
    QJsonArray scans = user["healthData"].toArray();

    QJsonArray measurementArr;
    for (int i = 0; i < scan->getMeasurements().length(); i++) {
        measurementArr.append(scan->getMeasurements()[i]);
    }
    QJsonObject scanObj;
    scanObj["date"] = scan->getDateTime().toString();
    scanObj["measurements"] = measurementArr;

    scans.append(scanObj);

    user["healthData"] = scans;

    userData.insert(index, user);

    return saveToJson();
}


bool JsonPersistence::deleteUser(const QString& email)
{
    int index = findIndex(email);
    if (index == -1) {
        return false;
    }
    userData.removeAt(index);
    return saveToJson();
}

QList<UserProfile*> JsonPersistence::loadUsers() const
{
    QList<UserProfile*> users;
    for (const QJsonValue& user : userData) {
            users.append(jsonToUserProfile(user.toObject()));
    }
    return users;
}

bool JsonPersistence::saveToJson() const
{
    QFile file(filePath);
    file.open(QIODevice::WriteOnly);

    QJsonDocument doc(userData);
    file.write(doc.toJson());
    file.close();
    return true;
}

bool JsonPersistence::loadFromJson()
{
    QFile file(filePath);
    if (!file.exists()) {
        return true;
    }

    file.open(QIODevice::ReadOnly);

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isArray()) {
        return false;
    }
    userData = doc.array();
    file.close();
    return true;
}

QJsonObject JsonPersistence::userProfileToJson(UserProfile* user) const
{
    QJsonObject json;
    json["firstName"] = user->getFirstName();
    json["lastName"] = user->getLastName();
    json["email"] = user->getEmail();
    json["gender"] = user->getGender();
    json["age"] = user->getAge();
    json["weight"] = user->getWeight();
    json["height"] = user->getHeight();

    QJsonArray scanArr;
    QList<Scan*> scans = user->getHealthData()->getScans();
    for (Scan* scan : scans) {
        QJsonArray measurementArr;
        for (int i = 0; i < scan->getMeasurements().length(); i++) {
            measurementArr.append(scan->getMeasurements()[i]);
        }
        QJsonObject scanObj;
        scanObj["date"] = scan->getDateTime().toString();
        scanObj["measurements"] = measurementArr;
        scanArr.append(scanObj);
    }
    json["healthData"] = scanArr;

    return json;
}

UserProfile* JsonPersistence::jsonToUserProfile(const QJsonObject& json) const
{
    UserProfile* user = new UserProfile(json["firstName"].toString(),
            json["lastName"].toString(), json["email"].toString(), json["gender"].toString(), json["age"].toInt(),
            json["weight"].toDouble(), json["height"].toDouble());

    QJsonArray scanArr = json["healthData"].toArray();
    for (QJsonValue scan : scanArr) {
        QJsonObject scanObj = scan.toObject();
        QJsonArray measurementArr = scanObj["measurements"].toArray();
        QList<int> nums;
        for (QJsonValue measurement : measurementArr){
            nums.append(measurement.toInt());
        }
        user->addScan(DataProcessor::createScan(nums, QDateTime::fromString(scanObj["date"].toString())));
    }
    return user;
}

int JsonPersistence::findIndex(const QString& email) const
{
    for (int i = 0; i < userData.size(); ++i) {
        if (userData[i].toObject().contains("email") && userData[i].toObject()["email"].toString() == email) {
            return i;
        }
    }
    return -1;
}
