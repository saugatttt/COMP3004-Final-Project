/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Home;
    QPushButton *createProfileButton;
    QPushButton *selectProfileButton;
    QPushButton *deleteProfileButton;
    QLabel *label;
    QPushButton *updateProfileButton;
    QWidget *tab_2;
    QWidget *scanTab;
    QPushButton *startScanButton;
    QCheckBox *jewelryToggle;
    QCheckBox *moisturizedToggle;
    QWidget *tab_3;
    QListView *scanListView;
    QLabel *label_2;
    QPushButton *confirmViewScanButton;
    QLabel *invalidSelectionLabel;
    QWidget *tab_4;
    QProgressBar *progressBar;
    QPushButton *chargeButton;
    QLabel *loggedInStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 20, 781, 521));
        Home = new QWidget();
        Home->setObjectName(QString::fromUtf8("Home"));
        createProfileButton = new QPushButton(Home);
        createProfileButton->setObjectName(QString::fromUtf8("createProfileButton"));
        createProfileButton->setGeometry(QRect(100, 220, 171, 31));
        selectProfileButton = new QPushButton(Home);
        selectProfileButton->setObjectName(QString::fromUtf8("selectProfileButton"));
        selectProfileButton->setGeometry(QRect(510, 220, 171, 31));
        deleteProfileButton = new QPushButton(Home);
        deleteProfileButton->setObjectName(QString::fromUtf8("deleteProfileButton"));
        deleteProfileButton->setGeometry(QRect(450, 270, 171, 31));
        label = new QLabel(Home);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 70, 361, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Serif"));
        font.setPointSize(30);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        updateProfileButton = new QPushButton(Home);
        updateProfileButton->setObjectName(QString::fromUtf8("updateProfileButton"));
        updateProfileButton->setGeometry(QRect(160, 270, 171, 31));
        tabWidget->addTab(Home, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        scanTab = new QWidget();
        scanTab->setObjectName(QString::fromUtf8("scanTab"));
        startScanButton = new QPushButton(scanTab);
        startScanButton->setObjectName(QString::fromUtf8("startScanButton"));
        startScanButton->setGeometry(QRect(240, 220, 251, 41));
        jewelryToggle = new QCheckBox(scanTab);
        jewelryToggle->setObjectName(QString::fromUtf8("jewelryToggle"));
        jewelryToggle->setGeometry(QRect(240, 160, 171, 23));
        moisturizedToggle = new QCheckBox(scanTab);
        moisturizedToggle->setObjectName(QString::fromUtf8("moisturizedToggle"));
        moisturizedToggle->setGeometry(QRect(240, 190, 211, 23));
        tabWidget->addTab(scanTab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        scanListView = new QListView(tab_3);
        scanListView->setObjectName(QString::fromUtf8("scanListView"));
        scanListView->setGeometry(QRect(30, 50, 711, 321));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 221, 17));
        confirmViewScanButton = new QPushButton(tab_3);
        confirmViewScanButton->setObjectName(QString::fromUtf8("confirmViewScanButton"));
        confirmViewScanButton->setGeometry(QRect(30, 420, 151, 41));
        invalidSelectionLabel = new QLabel(tab_3);
        invalidSelectionLabel->setObjectName(QString::fromUtf8("invalidSelectionLabel"));
        invalidSelectionLabel->setGeometry(QRect(30, 390, 391, 17));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 0, 118, 23));
        progressBar->setValue(24);
        chargeButton = new QPushButton(centralwidget);
        chargeButton->setObjectName(QString::fromUtf8("chargeButton"));
        chargeButton->setGeometry(QRect(130, 0, 71, 21));
        loggedInStatus = new QLabel(centralwidget);
        loggedInStatus->setObjectName(QString::fromUtf8("loggedInStatus"));
        loggedInStatus->setGeometry(QRect(430, 0, 351, 31));
        loggedInStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(confirmViewScanButton, SIGNAL(released()), MainWindow, SLOT(setFocus()));

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createProfileButton->setText(QCoreApplication::translate("MainWindow", "Create New Profile", nullptr));
        selectProfileButton->setText(QCoreApplication::translate("MainWindow", "Select Profile", nullptr));
        deleteProfileButton->setText(QCoreApplication::translate("MainWindow", "Delete Profile", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RaDoTech \n"
"User Interface", nullptr));
        updateProfileButton->setText(QCoreApplication::translate("MainWindow", "Update Profile", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Home), QCoreApplication::translate("MainWindow", "Home", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Profiles", nullptr));
        startScanButton->setText(QCoreApplication::translate("MainWindow", "Start Scan", nullptr));
        jewelryToggle->setText(QCoreApplication::translate("MainWindow", "Take off your jewelry", nullptr));
        moisturizedToggle->setText(QCoreApplication::translate("MainWindow", "Moisturize your skin", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(scanTab), QCoreApplication::translate("MainWindow", "Scan", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select the scan you wish to view", nullptr));
        confirmViewScanButton->setText(QCoreApplication::translate("MainWindow", "View Scan", nullptr));
        invalidSelectionLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "History", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Recommendations", nullptr));
        chargeButton->setText(QCoreApplication::translate("MainWindow", "Charge", nullptr));
        loggedInStatus->setText(QCoreApplication::translate("MainWindow", "Logged out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
