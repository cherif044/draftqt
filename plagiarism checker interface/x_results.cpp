#include "x_results.h"
#include "ui_x_results.h"
#include"mainwindow.h"
x_results::x_results(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::x_results)
{
    ui->setupUi(this);
}

x_results::~x_results()
{
    delete ui;
}





