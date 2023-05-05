#ifndef X_RESULTS_H
#define X_RESULTS_H

#include <QMainWindow>
#include "ui_x_results.h"

namespace Ui {
class x_results;
}

class x_results : public QMainWindow
{
    Q_OBJECT

public:
    Ui::x_results *getUi() const
    {
        return ui; // Return the ui pointer
    }
    explicit x_results(QWidget *parent = nullptr);
    ~x_results();
    void showresults(brute_force &a,Ui::x_results *ui)
    {
        for(int h=0;h<a.getfilex_vector().size();h++)
        {
            ui->resu->setText(ui->resu->text()+ a.getfilex_vector()[h]);
        }
        for(int i=1;i<=a.number_of_phrases_filex();i++)
        {
            if(a.getstorage().at(i).size()!=0)
            {
                for(int j=0;j<a.getstorage().at(i).size();j++)
                {
                    int startIndex=a.get_filex_sentences_index()[i-1]+a.getstorage().at(i).at(j).index_x;
                    int endIndex=startIndex+a.getstorage().at(i).at(j).text.length();
                    QString labelText = ui->resu->text(); // get the text of label_2 widget


                    // apply highlighting with span element and yellow background color to the specified section of text
                    QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

                    // combine the rest of the label text with the highlighted text
                    QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

                    ui->resu->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
                    ui->resu->setText(finalText); // set the final text as the text of label_2 widget

                }
            }
        }
    }
private slots:
    void on_pushButton_clicked();

private:
    Ui::x_results *ui;
};

#endif // X_RESULTS_H
