#ifndef USERPROFILE_H
#define USERPROFILE_H

#include "HealthData.h"
#include <QString>

class UserProfile {

private:
    QString firstName;
    QString lastName;
    QString email;
    QString gender;
    int age;
    float weight;
    float height;
    HealthData* healthData;

public:
    UserProfile(const QString &firstName, const QString &lastName, const QString& email, const QString &gender, int age, float weight, float height);
    ~UserProfile();

    QString getFirstName() const;
    QString getLastName() const;
    QString getEmail() const;
    QString getGender() const;
    int getAge() const;
    float getWeight() const;
    float getHeight() const;
    HealthData* getHealthData();

    void setFirstName(QString name);
    void setLastName(QString name);
    void setEmail(QString a);
    void setGender(QString g);
    void setAge(int a);
    void setWeight(float w);
    void setHeight(float h);

    void addScan(Scan* scan);

};

#endif
