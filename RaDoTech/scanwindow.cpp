#include "scanwindow.h"
#include "ui_scanwindow.h"

ScanWindow::ScanWindow(QWidget *parent, QList<int>* list) :
    QDialog(parent),
    list(list),
    index(0),
    generator(new DataGenerator()),
    ui(new Ui::ScanWindow)
{
    ui->setupUi(this);
    connect(ui->scanButton, SIGNAL(released()), this, SLOT (handleScanPress()));
}

ScanWindow::~ScanWindow()
{
    delete ui;
    delete generator;
}

void ScanWindow::handleScanPress()
{
    if(index > 23){    //todo: handle this case better later - probably exit the window or change display to "Done"
        QMessageBox msgError;
        msgError.setText("All scans complete");
        msgError.setIcon(QMessageBox::Warning);
        msgError.exec();
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
    int scanResult = generator->generateMeasurement(index, 0); //todo: set up globalrandomizer (second param)
    list->append(scanResult);

    index ++;

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
}

