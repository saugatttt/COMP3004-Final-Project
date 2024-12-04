#include "UserProfile.h"

UserProfile::UserProfile(const QString& fN, const QString& lN, const QString& email, const QString& gen, int a, float w, float h)
    : firstName(fN), lastName(lN), email(email), gender(gen), age(a), weight(w), height(h)
{
    healthData = new HealthData();
}

QString UserProfile::getFirstName() const {
    return firstName;
}

QString UserProfile::getLastName() const {
    return lastName;
}

QString UserProfile::getEmail() const {
    return email;
}

QString UserProfile::getGender() const {
    return gender;
}

int UserProfile::getAge() const {
    return age;
}

float UserProfile::getWeight() const {
    return weight;
}

float UserProfile::getHeight() const {
    return height;
}

HealthData* UserProfile::getHealthData() {
    return healthData;
}
