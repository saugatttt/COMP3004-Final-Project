#include "chartwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QVBoxLayout>
#include <QFont>
#include <QBrush>
#include <QColor>

using namespace QtCharts;

ChartWindow::ChartWindow(QWidget *parent, QDateTime date, const QList<int>& measurements, const QList<int>& healthStatus) :
    QDialog(parent), date(date), measurements(measurements), healthStatus(healthStatus),
    ui(new Ui::ChartWindow) {
    ui->setupUi(this);

    int numGroups = measurements.size() / 2; // Number of measurement groups (e.g., H1, H2, ..., F6)

    // Create two QBarSets: one for Left (L) and one for Right (R)
    QBarSet *setL = new QBarSet("Left (L)");
    QBarSet *setR = new QBarSet("Right (R)");

    // Lists to store bar colors
    QList<QColor> barColorsL;
    QList<QColor> barColorsR;

    // Add measurements to QBarSets
    for(int i = 0; i < numGroups; i++) {
        // Assign measurements
        int measurementL = measurements[2 * i];     // L measurement
        int measurementR = measurements[2 * i + 1]; // R measurement

        *setL << measurementL;
        *setR << measurementR;
    }

    QBarSeries *series = new QBarSeries();
    series->append(setL);
    series->append(setR);

    QChart *chart = new QChart();
    chart->addSeries(series);
    QString chartTitle = QString("Scan on %1").arg(date.toString("yyyy-MM-dd hh:mm"));
    chart->setTitle(chartTitle);
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Custom categories for the X-axis (e.g., H1, H2, ..., F6)
    QStringList categories;
    QString organs[] = {
        "lungs",
        "pericardium",
        "heart",
        "small<br>intestine",
        "lymph<br>vessel", 
        "large<br>intestine", 
        "spleen<br>pancreas",
        "liver",
        "kidney<br>adrenal glands", 
        "bladder",
        "gallbladder",
        "stomach",
    };

    for(int i = 0; i < numGroups; i++) {
        int healthStatusL = healthStatus[2 * i];
        int healthStatusR = healthStatus[2 * i + 1];
        if(i <= 6) {
            if (healthStatusL == 0 && healthStatusR == 0)
                categories << QString("H%1<br>%2").arg(i + 1).arg(organs[i]);
            else
                categories << QString("H%1<br>%2<br>(alert)").arg(i + 1).arg(organs[i]);
        }
        else {
            if (healthStatusL == 0 && healthStatusR == 0)
                categories << QString("F%1<br>%2").arg(i - 5).arg(organs[i]);
            else
                categories << QString("F%1<br>%2<br>(alert)").arg(i - 5).arg(organs[i]);
        }
    }

    // x-axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Measurement Points");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // y-axis
    QValueAxis *axisY = new QValueAxis();
    if (!measurements.isEmpty()) {
        int maxMeasurement = *std::max_element(measurements.begin(), measurements.end());
        axisY->setRange(0, maxMeasurement + 5); // Add some padding
    } else {
        axisY->setRange(0, 10); // Default range if measurements are empty
    }
    axisY->setTitleText("Ryodoraku Values");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    QFont titleFont;
    titleFont.setPixelSize(18);
    chart->setTitleFont(titleFont);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    setLayout(layout);
}

ChartWindow::~ChartWindow() {
    delete ui;
}
