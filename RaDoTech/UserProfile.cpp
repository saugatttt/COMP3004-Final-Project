#include "UserProfile.h"

UserProfile::UserProfile(const QString& fN, const QString& lN, const QString& email, const QString& gen, int a, float w, float h)
    : firstName(fN), lastName(lN), email(email), gender(gen), age(a), weight(w), height(h)
{
    healthData = new HealthData();
}

UserProfile::~UserProfile() {
    delete healthData;
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

void UserProfile::setFirstName(QString name) {
    firstName = name;
}

void UserProfile::setLastName(QString name) {
    lastName = name;
}

void UserProfile::setEmail(QString e) {
    email = e;
}

void UserProfile::setGender(QString g) {
    gender = g;
}

void UserProfile::setAge(int a) {
    age = a;
}

void UserProfile::setWeight(float w) {
    weight = w;
}

void UserProfile::setHeight(float h) {
    height = h;
}
