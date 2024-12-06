#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include "ui_chartwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDialog>
#include <QDate>
#include <QList>
#include <QtCharts/QChartView>

namespace Ui { class ChartWindow; }

class ChartWindow : public QDialog {
    Q_OBJECT

    public:
        explicit ChartWindow(QWidget *parent = nullptr, QDate date = QDate(),
            const QList<int>& measurements = QList<int>(),
                const QList<int>& healthStatus = QList<int>());
        ~ChartWindow();

    private:
        Ui::ChartWindow *ui;
        QDate date;
        QList<int> measurements;
        QList<int> healthStatus;
};

#endif // CHARTWINDOW_H
