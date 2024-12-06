/********************************************************************************
** Form generated from reading UI file 'updateprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEPROFILEDIALOG_H
#define UI_UPDATEPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateProfileDialog
{
public:
    QPushButton *cancelProfileButton;
    QPushButton *confirmProfileButton;
    QLabel *label_8;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLineEdit *emailUpdateProfileEdit;
    QLineEdit *lastNameUpdateProfileEdit;
    QLabel *label_10;
    QLineEdit *heightUpdateProfileEdit;
    QLineEdit *firstNameUpdateProfileEdit;
    QLabel *label_11;
    QLineEdit *weightUpdateProfileEdit;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *ageUpdateProfileEdit;
    QLineEdit *genderUpdateProfileEdit;
    QLabel *label_15;
    QLabel *invalidEntryLabel;

    void setupUi(QDialog *UpdateProfileDialog)
    {
        if (UpdateProfileDialog->objectName().isEmpty())
            UpdateProfileDialog->setObjectName(QString::fromUtf8("UpdateProfileDialog"));
        UpdateProfileDialog->resize(490, 435);
        cancelProfileButton = new QPushButton(UpdateProfileDialog);
        cancelProfileButton->setObjectName(QString::fromUtf8("cancelProfileButton"));
        cancelProfileButton->setGeometry(QRect(270, 370, 83, 25));
        confirmProfileButton = new QPushButton(UpdateProfileDialog);
        confirmProfileButton->setObjectName(QString::fromUtf8("confirmProfileButton"));
        confirmProfileButton->setGeometry(QRect(370, 370, 83, 25));
        label_8 = new QLabel(UpdateProfileDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 30, 361, 25));
        gridLayoutWidget = new QWidget(UpdateProfileDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 80, 401, 236));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(80);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 11, 0, 1, 1);

        emailUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        emailUpdateProfileEdit->setObjectName(QString::fromUtf8("emailUpdateProfileEdit"));

        gridLayout_2->addWidget(emailUpdateProfileEdit, 4, 1, 1, 1);

        lastNameUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        lastNameUpdateProfileEdit->setObjectName(QString::fromUtf8("lastNameUpdateProfileEdit"));

        gridLayout_2->addWidget(lastNameUpdateProfileEdit, 3, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 12, 0, 1, 1);

        heightUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        heightUpdateProfileEdit->setObjectName(QString::fromUtf8("heightUpdateProfileEdit"));

        gridLayout_2->addWidget(heightUpdateProfileEdit, 12, 1, 1, 1);

        firstNameUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        firstNameUpdateProfileEdit->setObjectName(QString::fromUtf8("firstNameUpdateProfileEdit"));

        gridLayout_2->addWidget(firstNameUpdateProfileEdit, 2, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 5, 0, 1, 1);

        weightUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        weightUpdateProfileEdit->setObjectName(QString::fromUtf8("weightUpdateProfileEdit"));

        gridLayout_2->addWidget(weightUpdateProfileEdit, 11, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 0, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 2, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 4, 0, 1, 1);

        ageUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        ageUpdateProfileEdit->setObjectName(QString::fromUtf8("ageUpdateProfileEdit"));

        gridLayout_2->addWidget(ageUpdateProfileEdit, 9, 1, 1, 1);

        genderUpdateProfileEdit = new QLineEdit(gridLayoutWidget);
        genderUpdateProfileEdit->setObjectName(QString::fromUtf8("genderUpdateProfileEdit"));

        gridLayout_2->addWidget(genderUpdateProfileEdit, 5, 1, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 9, 0, 1, 1);

        invalidEntryLabel = new QLabel(UpdateProfileDialog);
        invalidEntryLabel->setObjectName(QString::fromUtf8("invalidEntryLabel"));
        invalidEntryLabel->setEnabled(true);
        invalidEntryLabel->setGeometry(QRect(50, 330, 371, 25));
        QWidget::setTabOrder(firstNameUpdateProfileEdit, lastNameUpdateProfileEdit);
        QWidget::setTabOrder(lastNameUpdateProfileEdit, emailUpdateProfileEdit);
        QWidget::setTabOrder(emailUpdateProfileEdit, genderUpdateProfileEdit);
        QWidget::setTabOrder(genderUpdateProfileEdit, ageUpdateProfileEdit);
        QWidget::setTabOrder(ageUpdateProfileEdit, weightUpdateProfileEdit);
        QWidget::setTabOrder(weightUpdateProfileEdit, heightUpdateProfileEdit);
        QWidget::setTabOrder(heightUpdateProfileEdit, cancelProfileButton);
        QWidget::setTabOrder(cancelProfileButton, confirmProfileButton);

        retranslateUi(UpdateProfileDialog);

        QMetaObject::connectSlotsByName(UpdateProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateProfileDialog)
    {
        UpdateProfileDialog->setWindowTitle(QCoreApplication::translate("UpdateProfileDialog", "Dialog", nullptr));
        cancelProfileButton->setText(QCoreApplication::translate("UpdateProfileDialog", "Cancel", nullptr));
        confirmProfileButton->setText(QCoreApplication::translate("UpdateProfileDialog", "Update", nullptr));
        label_8->setText(QCoreApplication::translate("UpdateProfileDialog", "Fill out the information below:", nullptr));
        label_9->setText(QCoreApplication::translate("UpdateProfileDialog", "Weight:", nullptr));
        label_10->setText(QCoreApplication::translate("UpdateProfileDialog", "Height:", nullptr));
        label_11->setText(QCoreApplication::translate("UpdateProfileDialog", "Gender:", nullptr));
        label_12->setText(QCoreApplication::translate("UpdateProfileDialog", "Last name:", nullptr));
        label_13->setText(QCoreApplication::translate("UpdateProfileDialog", "First name:", nullptr));
        label_14->setText(QCoreApplication::translate("UpdateProfileDialog", "Email address:", nullptr));
        label_15->setText(QCoreApplication::translate("UpdateProfileDialog", "Age:", nullptr));
        invalidEntryLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UpdateProfileDialog: public Ui_UpdateProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEPROFILEDIALOG_H
