#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include "ui_chartwindow.h"
#include <Scan.h>
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QDateTime>
#include <QList>
#include <QtCharts/QChartView>

namespace Ui { class ChartWindow; }

class ChartWindow : public QDialog {
    Q_OBJECT

    public:
        explicit ChartWindow(QWidget *parent = nullptr, QDateTime date = QDateTime(),
            const QList<int>& measurements = QList<int>(),
                const QList<HealthStatus>& healthStatus = QList<HealthStatus>());
        ~ChartWindow();

    private:
        Ui::ChartWindow *ui;
        QDateTime date;
        QList<int> measurements;
        QList<HealthStatus> healthStatus;
};

#endif // CHARTWINDOW_H
