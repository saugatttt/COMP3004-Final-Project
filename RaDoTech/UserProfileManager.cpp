#include "UserProfileManager.h"
#include <QDebug>

UserProfileManager::UserProfileManager(const QString &filePath, QObject *parent)
    : QObject(parent), persistenceStrategy(filePath)
{
    users = persistenceStrategy.loadUsers();
}

UserProfileManager::~UserProfileManager()
{
}

bool UserProfileManager::createUserProfile(const QString& firstName, const QString& lastName, const QString& email, const QString& gender, int age, float weight, float height)
{
    UserProfile* newUser = new UserProfile(firstName, lastName, email, gender, age, weight, height);
    if (persistenceStrategy.addUser(newUser)) {
        users.append(newUser);
        return true;
    }
    return false;
}

bool UserProfileManager::deleteUserProfile(const QString& email)
{
    for (int i = 0; i < users.size(); ++i) {
        if (users[i]->getEmail() == email) {
            if (persistenceStrategy.deleteUser(email)) {
                users.removeAt(i);
                return true;
            }
            return false;
        }
    }
    return false;
}

QList<UserProfile*> UserProfileManager::getUsers() const
{
    return users;
}
