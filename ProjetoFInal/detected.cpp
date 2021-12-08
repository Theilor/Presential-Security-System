#include "detected.h"
#include "ui_detected.h"

detected::detected(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detected)
{
    ui->setupUi(this);
}

detected::~detected()
{
    delete ui;
}
