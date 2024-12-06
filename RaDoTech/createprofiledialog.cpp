#include "createprofiledialog.h"
#include "ui_createprofiledialog.h"

CreateProfileDialog::CreateProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProfileDialog)
{
    ui->setupUi(this);
}

Ui::CreateProfileDialog* CreateProfileDialog::getUi() {
    return ui;
}

CreateProfileDialog::~CreateProfileDialog()
{
    delete ui;
}
