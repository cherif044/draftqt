#include "file1_results.h"
#include "ui_file1_results.h"
#include "mainwindow.h"
file1_results::file1_results(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::file1_results)
{
    // Initialize the ui object
    ui->setupUi(this);
}
file1_results::~file1_results()
{
    delete ui;
}
void showresults(brute_force &a)
{
    for(int h=0;h<a.getfilex_vector().size();h++)
    {
        ui->res->setText(ui->res->text()+ a.getfilex_vector()[h]);
    }
    for(int i=1;i<=a.number_of_phrases_filex();i++)
    {
        if(a.getstorage().at(i).size()!=0)
        {
            for(int j=0;j<a.getstorage().at(i).size();j++)
            {
                int startIndex=a.get_filex_sentences_index()[i-1]+a.getstorage().at(i).at(j).index_x;
                int endIndex=startIndex+a.getstorage().at(i).at(j).text.length();
                QString labelText = ui->res->text(); // get the text of label_2 widget


                // apply highlighting with span element and yellow background color to the specified section of text
                QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

                // combine the rest of the label text with the highlighted text
                QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

                ui->res->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
                ui->res->setText(finalText); // set the final text as the text of label_2 widget

            }
        }
    }
}
