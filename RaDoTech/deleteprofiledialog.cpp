#include "deleteprofiledialog.h"
#include "ui_deleteprofiledialog.h"

DeleteProfileDialog::DeleteProfileDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProfileDialog)
{
    ui->setupUi(this);
}

Ui::DeleteProfileDialog* DeleteProfileDialog::getUi() {
    return ui;
}

DeleteProfileDialog::~DeleteProfileDialog()
{
    delete ui;
}
