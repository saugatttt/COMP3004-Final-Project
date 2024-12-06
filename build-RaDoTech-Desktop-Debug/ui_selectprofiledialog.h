/********************************************************************************
** Form generated from reading UI file 'selectprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPROFILEDIALOG_H
#define UI_SELECTPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectProfileDialog
{
public:
    QPushButton *cancelProfileButton;
    QPushButton *confirmProfileButton;
    QListView *userListView;
    QLabel *label_15;
    QLabel *invalidSelectionLabel;

    void setupUi(QDialog *SelectProfileDialog)
    {
        if (SelectProfileDialog->objectName().isEmpty())
            SelectProfileDialog->setObjectName(QString::fromUtf8("SelectProfileDialog"));
        SelectProfileDialog->resize(490, 435);
        cancelProfileButton = new QPushButton(SelectProfileDialog);
        cancelProfileButton->setObjectName(QString::fromUtf8("cancelProfileButton"));
        cancelProfileButton->setGeometry(QRect(270, 370, 83, 25));
        confirmProfileButton = new QPushButton(SelectProfileDialog);
        confirmProfileButton->setObjectName(QString::fromUtf8("confirmProfileButton"));
        confirmProfileButton->setGeometry(QRect(370, 370, 83, 25));
        userListView = new QListView(SelectProfileDialog);
        userListView->setObjectName(QString::fromUtf8("userListView"));
        userListView->setGeometry(QRect(40, 70, 361, 241));
        label_15 = new QLabel(SelectProfileDialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 30, 361, 25));
        invalidSelectionLabel = new QLabel(SelectProfileDialog);
        invalidSelectionLabel->setObjectName(QString::fromUtf8("invalidSelectionLabel"));
        invalidSelectionLabel->setEnabled(true);
        invalidSelectionLabel->setGeometry(QRect(40, 330, 371, 25));

        retranslateUi(SelectProfileDialog);

        QMetaObject::connectSlotsByName(SelectProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectProfileDialog)
    {
        SelectProfileDialog->setWindowTitle(QCoreApplication::translate("SelectProfileDialog", "Dialog", nullptr));
        cancelProfileButton->setText(QCoreApplication::translate("SelectProfileDialog", "Cancel", nullptr));
        confirmProfileButton->setText(QCoreApplication::translate("SelectProfileDialog", "Log in", nullptr));
        label_15->setText(QCoreApplication::translate("SelectProfileDialog", "Select the user you wish to log in with:", nullptr));
        invalidSelectionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectProfileDialog: public Ui_SelectProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPROFILEDIALOG_H
