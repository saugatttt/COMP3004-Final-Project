#ifndef SCANWINDOW_H
#define SCANWINDOW_H

#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include "DataGenerator.h"
#include "RadoTechDevice.h"

namespace Ui {
class ScanWindow;
}

class ScanWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ScanWindow(QWidget *parent = nullptr, QList<int>* list = nullptr, RadoTechDevice* device = nullptr);
    ~ScanWindow();

private slots:
    void handleScanPress();
    void handleSaveExitPress();

private:
    Ui::ScanWindow *ui;
    QList<int>* list;
    int index;
    RadoTechDevice* device;
};

#endif // SCANWINDOW_H
