#include "won.h"
#include "ui_won.h"

won::won(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::won)
{
    ui->setupUi(this);
}

won::~won()
{
    delete ui;
}
