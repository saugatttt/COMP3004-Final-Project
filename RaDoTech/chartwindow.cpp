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

ChartWindow::ChartWindow(QWidget *parent, QDate date, const QList<int>& measurements, const QList<int>& healthStatus) :
    QDialog(parent), date(date), measurements(measurements), healthStatus(healthStatus),
    ui(new Ui::ChartWindow) {
    ui->setupUi(this);

    QBarSeries* series = new QBarSeries();
    QBarSet* set = new QBarSet("Measurements");
    QList<QColor> barColors;

    for(int i = 0; i < measurements.size(); ++i) {
        *set << measurements[i];
        if(healthStatus[i] == 0) {
            barColors.append(QColor(Qt::green));
        }
        else {
            barColors.append(QColor(Qt::red));
        }
    }
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    QString chartTitle = QString("Measurements on %1").arg(date.toString("yyyy-MM-dd"));
    chart->setTitle(chartTitle);
    chart->setAnimationOptions(QChart::SeriesAnimations);

     // H1 L, H1 R, H2 L, H2 R, ..., H6 L, H6 R, F1 L, F1 R, ..., F6 L, F6 R
    QStringList categories;
    for(int i = 1; i <= 6; ++i) {
        categories << QString("H%1 L").arg(i) << QString("H%1 R").arg(i);
    }
    for(int i = 1; i <= 6; ++i) {
        categories << QString("F%1 L").arg(i) << QString("F%1 R").arg(i);
    }

    // x-axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setTitleText("Measurement Points");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // y-axis
    QValueAxis *axisY = new QValueAxis();
    int maxMeasurement = *std::max_element(measurements.begin(), measurements.end());
    axisY->setRange(0, maxMeasurement + 5); // Add some padding
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
