#include "updateprofiledialog.h"
#include "ui_updateprofiledialog.h"

UpdateProfileDialog::UpdateProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateProfileDialog)
{
    ui->setupUi(this);
}

Ui::UpdateProfileDialog* UpdateProfileDialog::getUi() {
    return ui;
}

UpdateProfileDialog::~UpdateProfileDialog()
{
    delete ui;
}
