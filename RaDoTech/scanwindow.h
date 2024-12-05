#ifndef SCANWINDOW_H
#define SCANWINDOW_H

#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include "DataGenerator.h"

#include"battery.h"


namespace Ui {
class ScanWindow;
}

class ScanWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScanWindow(QWidget *parent = nullptr, QList<int>* list = nullptr, battery* batteryObj = nullptr);
    ~ScanWindow();

private slots:
    void handleScanPress();

private:
    Ui::ScanWindow *ui;
    QList<int>* list;
    int index;
    DataGenerator* generator;
    battery* batteryObj;
};

#endif // SCANWINDOW_H
