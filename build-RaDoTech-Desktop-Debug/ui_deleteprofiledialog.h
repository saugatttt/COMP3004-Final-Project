/********************************************************************************
** Form generated from reading UI file 'deleteprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEPROFILEDIALOG_H
#define UI_DELETEPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteProfileDialog
{
public:
    QPushButton *cancelProfileButton;
    QPushButton *confirmProfileButton;
    QLabel *label_15;
    QListView *userListView;
    QLabel *invalidSelectionLabel;

    void setupUi(QDialog *DeleteProfileDialog)
    {
        if (DeleteProfileDialog->objectName().isEmpty())
            DeleteProfileDialog->setObjectName(QString::fromUtf8("DeleteProfileDialog"));
        DeleteProfileDialog->resize(490, 435);
        cancelProfileButton = new QPushButton(DeleteProfileDialog);
        cancelProfileButton->setObjectName(QString::fromUtf8("cancelProfileButton"));
        cancelProfileButton->setGeometry(QRect(270, 370, 83, 25));
        confirmProfileButton = new QPushButton(DeleteProfileDialog);
        confirmProfileButton->setObjectName(QString::fromUtf8("confirmProfileButton"));
        confirmProfileButton->setGeometry(QRect(370, 370, 83, 25));
        label_15 = new QLabel(DeleteProfileDialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(40, 30, 361, 25));
        userListView = new QListView(DeleteProfileDialog);
        userListView->setObjectName(QString::fromUtf8("userListView"));
        userListView->setGeometry(QRect(40, 70, 361, 241));
        invalidSelectionLabel = new QLabel(DeleteProfileDialog);
        invalidSelectionLabel->setObjectName(QString::fromUtf8("invalidSelectionLabel"));
        invalidSelectionLabel->setEnabled(true);
        invalidSelectionLabel->setGeometry(QRect(40, 330, 371, 25));

        retranslateUi(DeleteProfileDialog);

        QMetaObject::connectSlotsByName(DeleteProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *DeleteProfileDialog)
    {
        DeleteProfileDialog->setWindowTitle(QCoreApplication::translate("DeleteProfileDialog", "Dialog", nullptr));
        cancelProfileButton->setText(QCoreApplication::translate("DeleteProfileDialog", "Cancel", nullptr));
        confirmProfileButton->setText(QCoreApplication::translate("DeleteProfileDialog", "Delete", nullptr));
        label_15->setText(QCoreApplication::translate("DeleteProfileDialog", "Select the user you wish to delete:", nullptr));
        invalidSelectionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DeleteProfileDialog: public Ui_DeleteProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEPROFILEDIALOG_H
