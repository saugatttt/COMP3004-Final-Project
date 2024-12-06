/********************************************************************************
** Form generated from reading UI file 'chartwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTWINDOW_H
#define UI_CHARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartWindow
{
public:
    QWidget *chartContainer;

    void setupUi(QDialog *ChartWindow)
    {
        if (ChartWindow->objectName().isEmpty())
            ChartWindow->setObjectName(QString::fromUtf8("ChartWindow"));
        ChartWindow->resize(400, 300);
        chartContainer = new QWidget(ChartWindow);
        chartContainer->setObjectName(QString::fromUtf8("chartContainer"));
        chartContainer->setGeometry(QRect(10, 10, 381, 281));

        retranslateUi(ChartWindow);

        QMetaObject::connectSlotsByName(ChartWindow);
    } // setupUi

    void retranslateUi(QDialog *ChartWindow)
    {
        ChartWindow->setWindowTitle(QCoreApplication::translate("ChartWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChartWindow: public Ui_ChartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTWINDOW_H
