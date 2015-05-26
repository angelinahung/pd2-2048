#include "puzzle.h"
#include "ui_puzzle.h"

puzzle::puzzle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::puzzle)
{
    ui->setupUi(this);
}

puzzle::~puzzle()
{
    delete ui;
}
