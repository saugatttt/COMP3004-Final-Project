#ifndef CREATEPROFILEDIALOG_H
#define CREATEPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class CreateProfileDialog;
}

class CreateProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProfileDialog(QWidget *parent = nullptr);
    ~CreateProfileDialog();

    Ui::CreateProfileDialog* getUi();

private:
    Ui::CreateProfileDialog *ui;
};

#endif // CREATEPROFILEDIALOG_H
