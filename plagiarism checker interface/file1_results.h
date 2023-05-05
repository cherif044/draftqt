#ifndef FILE1_RESULTS_H
#define FILE1_RESULTS_H

#include <QMainWindow>

namespace Ui {
class file1_results;
}

class file1_results : public QMainWindow
{
    Q_OBJECT

public:
    explicit file1_results(QWidget *parent = nullptr);
    ~file1_results();

private:
    Ui::file1_results *ui; // declare the ui object
};

#endif

 // FILE1_RESULTS_H
