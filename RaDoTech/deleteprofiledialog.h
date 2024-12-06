#ifndef DELETEPROFILEDIALOG_H
#define DELETEPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class DeleteProfileDialog;
}

class DeleteProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteProfileDialog(QWidget *parent = nullptr);
    ~DeleteProfileDialog();

    Ui::DeleteProfileDialog* getUi();

private:
    Ui::DeleteProfileDialog *ui;
};

#endif // DELETEPROFILEDIALOG_H
