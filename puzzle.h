#ifndef PUZZLE_H
#define PUZZLE_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>

namespace Ui {
class puzzle;
}

class puzzle : public QMainWindow
{
    Q_OBJECT

public:
    explicit puzzle(QWidget *parent = 0);
    ~puzzle();

signals:
    void reset();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    QPixmap *pix;
    int score;
    void keyPressEvent(QKeyEvent *event);
    QLabel* lab[16];
    QLCDNumber* n[1];
    Ui::puzzle *ui;
    int gameover();
    void output();
    int calculate[16];
    int randomnum();
    void addright();
    void addleft();
    void addup();
    void adddown();
    void over();
};

#endif // PUZZLE_H
