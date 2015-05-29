#ifndef RESULT_H
#define RESULT_H

#include <QMainWindow>

namespace Ui {
class result;
}

class result : public QMainWindow
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = 0);
    ~result();
signals:
    void reset();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::result *ui;
};

#endif // RESULT_H
