/********************************************************************************
** Form generated from reading UI file 'scanwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANWINDOW_H
#define UI_SCANWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_ScanWindow
{
public:
    QPushButton *scanButton;
    QRadioButton *contactButton;
    QLabel *label;
    QPushButton *saveExitButton;

    void setupUi(QDialog *ScanWindow)
    {
        if (ScanWindow->objectName().isEmpty())
            ScanWindow->setObjectName(QString::fromUtf8("ScanWindow"));
        ScanWindow->resize(400, 300);
        scanButton = new QPushButton(ScanWindow);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));
        scanButton->setGeometry(QRect(130, 160, 141, 41));
        contactButton = new QRadioButton(ScanWindow);
        contactButton->setObjectName(QString::fromUtf8("contactButton"));
        contactButton->setGeometry(QRect(120, 130, 191, 23));
        label = new QLabel(ScanWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 100, 301, 31));
        saveExitButton = new QPushButton(ScanWindow);
        saveExitButton->setObjectName(QString::fromUtf8("saveExitButton"));
        saveExitButton->setGeometry(QRect(70, 130, 121, 31));

        retranslateUi(ScanWindow);
        QObject::connect(scanButton, SIGNAL(released()), ScanWindow, SLOT(setFocus()));
        QObject::connect(saveExitButton, SIGNAL(released()), ScanWindow, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(ScanWindow);
    } // setupUi

    void retranslateUi(QDialog *ScanWindow)
    {
        ScanWindow->setWindowTitle(QCoreApplication::translate("ScanWindow", "Dialog", nullptr));
        scanButton->setText(QCoreApplication::translate("ScanWindow", "Scan", nullptr));
        contactButton->setText(QCoreApplication::translate("ScanWindow", "Bring device to skin", nullptr));
        label->setText(QCoreApplication::translate("ScanWindow", "Next body part to scan: H1, left side", nullptr));
        saveExitButton->setText(QCoreApplication::translate("ScanWindow", "Save and Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScanWindow: public Ui_ScanWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANWINDOW_H
