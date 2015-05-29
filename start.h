#ifndef START_H
#define START_H

#include <QWidget>
#include "puzzle.h"
namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_pushButton_clicked();

private:
    Ui::start *ui;
    puzzle *puzzlegame;
};

#endif // START_H
