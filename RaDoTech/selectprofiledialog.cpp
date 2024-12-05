#include "selectprofiledialog.h"
#include "ui_selectprofiledialog.h"

SelectProfileDialog::SelectProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectProfileDialog)
{
    ui->setupUi(this);
}

Ui::SelectProfileDialog* SelectProfileDialog::getUi() {
    return ui;
}

SelectProfileDialog::~SelectProfileDialog()
{
    delete ui;
}
