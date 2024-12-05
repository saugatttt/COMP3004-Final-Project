#include "scanwindow.h"
#include "ui_scanwindow.h"
#include <random>


ScanWindow::ScanWindow(QWidget *parent, QList<int>* list, battery* bat) :
    QDialog(parent),
    list(list),
    index(0),
    generator(new DataGenerator()),
    ui(new Ui::ScanWindow),
    batteryObj(bat)
{

    ui->setupUi(this);
    connect(ui->scanButton, SIGNAL(released()), this, SLOT (handleScanPress()));
    connect(ui->saveExitButton, SIGNAL(released()), this, SLOT (handleSaveExitPress()));
    ui->saveExitButton->setVisible(false);

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0 - GLOBAL_RAND_RANGE, GLOBAL_RAND_RANGE);
    globalDeviation = dis(gen);  //will apply to all 24 measurements
}

ScanWindow::~ScanWindow()
{
    delete ui;
    delete generator;
}

void ScanWindow::handleSaveExitPress(){
    ScanWindow::close();
}

void ScanWindow::handleScanPress()
{
    if (batteryObj->getBatteryLevel() == 0) {
        batteryObj->showLowBatteryWarning();
        return;
    }
        //device not contacting skin
    if(!ui->contactButton->isChecked()){
        QMessageBox msgError;
        msgError.setText("You must bring device to skin before scanning");
        msgError.setIcon(QMessageBox::Warning);
        msgError.exec();
        return;
    }

    this->ui->contactButton->setChecked(false);
    int scanResult = generator->generateMeasurement(index, globalDeviation);
    list->append(scanResult);

    index ++;

    //scan complete
    if(index > 23){
        ui->label->setText("All scans complete!");
        ui->scanButton->setVisible(false);
        ui->contactButton->setVisible(false);
        ui->saveExitButton->setVisible(true);
        return;
    }

    //update GUI
    char letter;
    std::string num;
    if(index < 12){
        letter = 'H';
        num = std::to_string(index/2 + 1);
    }
    else {
        letter = 'F';
        num = std::to_string((index-12)/2 + 1);
    }
    std::string side;
    if((index%2) == 0)
        side = "left";
    else
        side = "right";

    std::string finalText = "Next body part to scan: ";
    finalText += letter;
    finalText += num;
    finalText += + ", " + side + " side";
    ui->label->setText(QString::fromStdString(finalText));
    batteryObj->decreaseBatteryLevel();

}

