#ifndef SELECTPROFILEDIALOG_H
#define SELECTPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class SelectProfileDialog;
}

class SelectProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectProfileDialog(QWidget *parent = nullptr);
    ~SelectProfileDialog();

    Ui::SelectProfileDialog* getUi();

private:
    Ui::SelectProfileDialog *ui;
};

#endif // SELECTPROFILEDIALOG_H
