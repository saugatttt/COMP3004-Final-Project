#ifndef JSONPERSISTENCE_H
#define JSONPERSISTENCE_H

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QUuid>
#include "UserProfile.h"

class JsonPersistence : public QObject
{
    Q_OBJECT

private:
    QString filePath;
    QJsonArray userData;

    QJsonObject userProfileToJson(UserProfile* user) const;
    UserProfile* jsonToUserProfile(const QJsonObject &json) const;
    bool loadFromJson();
    int findIndex(const QString& email) const;

public:
    explicit JsonPersistence(const QString &filePath, QObject *parent = nullptr);
    ~JsonPersistence();

    bool addUser(UserProfile* user);
    bool updateUser(const QString& firstName, const QString& lastName, const QString& email, const QString& gender, int age, float weight, float height);
    bool deleteUser(const QString& email);
    QList<UserProfile*> loadUsers() const;
    bool saveToJson() const;
};

#endif
