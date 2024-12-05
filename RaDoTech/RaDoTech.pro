QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deleteprofiledialog.cpp \
    HealthData.cpp \
    JsonPersistence.cpp \
    Scan.cpp \
    UserProfile.cpp \
    UserProfileManager.cpp \
    createprofiledialog.cpp \
    main.cpp \
    mainwindow.cpp \
    selectprofiledialog.cpp \
    updateprofiledialog.cpp

HEADERS += \
    deleteprofiledialog.h \
    HealthData.h \
    JsonPersistence.h \
    Scan.h \
    UserProfile.h \
    UserProfileManager.h \
    createprofiledialog.h \
    mainwindow.h \
    selectprofiledialog.h \
    updateprofiledialog.h

FORMS += \
    deleteprofiledialog.ui \
    createprofiledialog.ui \
    mainwindow.ui \
    selectprofiledialog.ui \
    updateprofiledialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
