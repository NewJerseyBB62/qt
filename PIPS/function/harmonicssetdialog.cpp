#include "harmonicssetdialog.h"
#include "ui_harmonicssetdialog.h"

HarmonicsSetDialog::HarmonicsSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HarmonicsSetDialog)
{
    ui->setupUi(this);
}

HarmonicsSetDialog::~HarmonicsSetDialog()
{
    delete ui;
}
