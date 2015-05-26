#ifndef PUZZLE_H
#define PUZZLE_H

#include <QMainWindow>

namespace Ui {
class puzzle;
}

class puzzle : public QMainWindow
{
    Q_OBJECT

public:
    explicit puzzle(QWidget *parent = 0);
    ~puzzle();

private:
    Ui::puzzle *ui;
};

#endif // PUZZLE_H
