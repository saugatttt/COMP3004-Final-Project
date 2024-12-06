#ifndef USERPROFILEMANAGER_H
#define USERPROFILEMANAGER_H

#include <QObject>
#include <QList>
#include "UserProfile.h"
#include "JsonPersistence.h"

class UserProfileManager : public QObject
{
    Q_OBJECT

private:
    QList<UserProfile*> users;
    JsonPersistence persistenceStrategy;

public:
    explicit UserProfileManager(const QString& filePath, QObject *parent = nullptr);
    ~UserProfileManager();

    bool createUserProfile(const QString& firstName, const QString& lastName, const QString& email, const QString& gender, int age, float weight, float height);
    bool updateUserProfile(const QString& firstName, const QString& lastName, const QString& email, const QString& gender, int age, float weight, float height);
    bool deleteUserProfile(const QString& email);
    bool addScan(const QString& email);

    const QList<UserProfile*>& getUsers() const;
};

#endif
