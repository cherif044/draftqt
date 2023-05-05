#ifndef X_RES_H
#define X_RES_H

#include <QMainWindow>
#include "ui_x_res.h"

namespace Ui {
class x_res;
}

class x_res : public QMainWindow
{
    Q_OBJECT

public:
    explicit x_res(QWidget *parent = nullptr);
    ~x_res();

private:
    Ui::x_res *ui;
};

#endif // X_RES_H
