#include "x_res.h"
#include "ui_x_res.h"

x_res::x_res(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::x_res)
{
    ui->setupUi(this);
}

x_res::~x_res()
{
    delete ui;
}
