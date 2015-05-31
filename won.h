#ifndef WON_H
#define WON_H

#include <QWidget>

namespace Ui {
class won;
}

class won : public QWidget
{
    Q_OBJECT

public:
    explicit won(QWidget *parent = 0);
    ~won();

private:
    Ui::won *ui;
};

#endif // WON_H
