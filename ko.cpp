#include "ko.h"
#include "ui_ko.h"

ko::ko(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ko)
{
    ui->setupUi(this);
}

ko::~ko()
{
    delete ui;
}

void ko::on_pushButton_2_clicked()
{
    close();
}
