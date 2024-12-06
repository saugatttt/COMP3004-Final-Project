/********************************************************************************
** Form generated from reading UI file 'createprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROFILEDIALOG_H
#define UI_CREATEPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateProfileDialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *emailCreateProfileEdit;
    QLineEdit *lastNameCreateProfileEdit;
    QLabel *label_7;
    QLineEdit *heightCreateProfileEdit;
    QLineEdit *firstNameCreateProfileEdit;
    QLabel *label_4;
    QLineEdit *weightCreateProfileEdit;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *ageCreateProfileEdit;
    QLineEdit *genderCreateProfileEdit;
    QLabel *label_5;
    QPushButton *cancelProfileButton;
    QPushButton *confirmProfileButton;
    QLabel *label_8;
    QLabel *invalidEntryLabel;

    void setupUi(QDialog *CreateProfileDialog)
    {
        if (CreateProfileDialog->objectName().isEmpty())
            CreateProfileDialog->setObjectName(QString::fromUtf8("CreateProfileDialog"));
        CreateProfileDialog->resize(490, 435);
        gridLayoutWidget = new QWidget(CreateProfileDialog);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 80, 401, 236));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(80);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 11, 0, 1, 1);

        emailCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        emailCreateProfileEdit->setObjectName(QString::fromUtf8("emailCreateProfileEdit"));

        gridLayout->addWidget(emailCreateProfileEdit, 4, 1, 1, 1);

        lastNameCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        lastNameCreateProfileEdit->setObjectName(QString::fromUtf8("lastNameCreateProfileEdit"));

        gridLayout->addWidget(lastNameCreateProfileEdit, 3, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 12, 0, 1, 1);

        heightCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        heightCreateProfileEdit->setObjectName(QString::fromUtf8("heightCreateProfileEdit"));

        gridLayout->addWidget(heightCreateProfileEdit, 12, 1, 1, 1);

        firstNameCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        firstNameCreateProfileEdit->setObjectName(QString::fromUtf8("firstNameCreateProfileEdit"));

        gridLayout->addWidget(firstNameCreateProfileEdit, 2, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        weightCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        weightCreateProfileEdit->setObjectName(QString::fromUtf8("weightCreateProfileEdit"));

        gridLayout->addWidget(weightCreateProfileEdit, 11, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        ageCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        ageCreateProfileEdit->setObjectName(QString::fromUtf8("ageCreateProfileEdit"));

        gridLayout->addWidget(ageCreateProfileEdit, 9, 1, 1, 1);

        genderCreateProfileEdit = new QLineEdit(gridLayoutWidget);
        genderCreateProfileEdit->setObjectName(QString::fromUtf8("genderCreateProfileEdit"));

        gridLayout->addWidget(genderCreateProfileEdit, 5, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        label_6->raise();
        label_7->raise();
        label_4->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        label_5->raise();
        heightCreateProfileEdit->raise();
        weightCreateProfileEdit->raise();
        ageCreateProfileEdit->raise();
        genderCreateProfileEdit->raise();
        emailCreateProfileEdit->raise();
        lastNameCreateProfileEdit->raise();
        firstNameCreateProfileEdit->raise();
        cancelProfileButton = new QPushButton(CreateProfileDialog);
        cancelProfileButton->setObjectName(QString::fromUtf8("cancelProfileButton"));
        cancelProfileButton->setGeometry(QRect(270, 370, 83, 25));
        confirmProfileButton = new QPushButton(CreateProfileDialog);
        confirmProfileButton->setObjectName(QString::fromUtf8("confirmProfileButton"));
        confirmProfileButton->setGeometry(QRect(370, 370, 83, 25));
        label_8 = new QLabel(CreateProfileDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 30, 361, 25));
        invalidEntryLabel = new QLabel(CreateProfileDialog);
        invalidEntryLabel->setObjectName(QString::fromUtf8("invalidEntryLabel"));
        invalidEntryLabel->setEnabled(true);
        invalidEntryLabel->setGeometry(QRect(50, 330, 371, 25));
        QWidget::setTabOrder(firstNameCreateProfileEdit, lastNameCreateProfileEdit);
        QWidget::setTabOrder(lastNameCreateProfileEdit, emailCreateProfileEdit);
        QWidget::setTabOrder(emailCreateProfileEdit, genderCreateProfileEdit);
        QWidget::setTabOrder(genderCreateProfileEdit, ageCreateProfileEdit);
        QWidget::setTabOrder(ageCreateProfileEdit, weightCreateProfileEdit);
        QWidget::setTabOrder(weightCreateProfileEdit, heightCreateProfileEdit);
        QWidget::setTabOrder(heightCreateProfileEdit, cancelProfileButton);
        QWidget::setTabOrder(cancelProfileButton, confirmProfileButton);

        retranslateUi(CreateProfileDialog);

        QMetaObject::connectSlotsByName(CreateProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateProfileDialog)
    {
        CreateProfileDialog->setWindowTitle(QCoreApplication::translate("CreateProfileDialog", "Dialog", nullptr));
        label_6->setText(QCoreApplication::translate("CreateProfileDialog", "Weight:", nullptr));
        label_7->setText(QCoreApplication::translate("CreateProfileDialog", "Height:", nullptr));
        label_4->setText(QCoreApplication::translate("CreateProfileDialog", "Gender:", nullptr));
        label_2->setText(QCoreApplication::translate("CreateProfileDialog", "Last name:", nullptr));
        label->setText(QCoreApplication::translate("CreateProfileDialog", "First name:", nullptr));
        label_3->setText(QCoreApplication::translate("CreateProfileDialog", "Email address:", nullptr));
        label_5->setText(QCoreApplication::translate("CreateProfileDialog", "Age:", nullptr));
        cancelProfileButton->setText(QCoreApplication::translate("CreateProfileDialog", "Cancel", nullptr));
        confirmProfileButton->setText(QCoreApplication::translate("CreateProfileDialog", "Create", nullptr));
        label_8->setText(QCoreApplication::translate("CreateProfileDialog", "Fill out the information below:", nullptr));
        invalidEntryLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateProfileDialog: public Ui_CreateProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFILEDIALOG_H
