#ifndef HARMONICSSETDIALOG_H
#define HARMONICSSETDIALOG_H

#include <QDialog>

namespace Ui {
class HarmonicsSetDialog;
}

class HarmonicsSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HarmonicsSetDialog(QWidget *parent = nullptr);
    ~HarmonicsSetDialog();

private:
    Ui::HarmonicsSetDialog *ui;
};

#endif // HARMONICSSETDIALOG_H
