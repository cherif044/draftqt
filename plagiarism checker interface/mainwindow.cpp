#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <sstream>
#include <QScrollArea>
#include"x_res.h""
#include <QLabel>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QTextCursor>
x_res *bu;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString file;

void MainWindow::on_pushButton_clicked()
{

        file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
        this->filename1 = file.toStdString();



}


void MainWindow::on_pushButton_2_clicked()
{

        file = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Text Files (*.txt);;All Files (*.*)"));
        this->filename2 = file.toStdString();


}

#include <sstream>

#include <sstream>

void output()
{
    std::cout << "cherif" << std::endl;
}

void MainWindow::on_pushButton_3_clicked()
{
    brute_force a(filename1,filename2);







    ui->label->setWordWrap(true);

    ui->label->setText("checking every sentence in file 1\n");
cout<<"sentence check: "<<endl;
    for (int j = 1; j <= a.number_of_phrases_filex(); j++)          // every phrase in filex vector
    {
        vector<logs> plagiarized;
cout<<"sentence : "<<j <<" of file x check "<<endl;
        for (int i = 1; i <= a.number_of_phrases_filey(); i++)
        {
           cout<<"checking with sentence: "<<i<<" of file y"<<endl;
            vector<char> temp = a.getsentence_filey(i);



            a.trial(temp, a.getsentence_filex(j),i,j,plagiarized);


            //if (tempI.size() > 0)
           // {
           //     ui->label->setText(ui->label->text()+QString("sentence: ") + QString::fromStdString(std::to_string(j)) + '\n');

           //     for (int z = 0; z < tempI.size(); z++)
           //     {
           //         ui->label->setText(ui->label->text()+QString("the phrase : (") + QString::fromStdString(tempI[z].text) +
            //                           QString(") is similar to a phrase in sentence: ") + QString::number(i) +
            //                           QString(" of the second file") + QString(" this phrase starts from word number: ") +
            //                           QString::number(tempI[z].index_x) + QString(" of the first file sentence and starts from the word: ") +
            //                           QString::number(tempI[z].index_y) + QString(" of the second file sentence") + QChar('\n'));
//
            //    }

           // }

        }
     a.push_storage(plagiarized);
    }

    ui->label_5->setWordWrap(true);

    for(int h=0;h<a.getfilex_vector().size();h++)
    {
        ui->label_5->setText(ui->label_5->text()+ a.getfilex_vector()[h]);
    }
    cout<<"sentences: "<<a.getstorage().size()<<endl;;
    for(int i =0;i<a.getstorage().size();i++)
    {
        cout<<"sentence: "<<i+1<<"has plagiarism phrases: "<<a.getstorage().at(i).size()<<endl;
        if(a.getstorage().at(i).size()>0)
        {
        for(int j=0;j<a.getstorage().at(i).size();j++)
        {



             int startIndex=a.get_filex_sentences_index()[i]+a.getstorage().at(i).at(j).start_x;
             int endIndex=startIndex+a.getstorage().at(i).at(j).text.length();
           // int startIndex=1;
            //int endIndex=3;
             cout<<"START INDEX= "<<startIndex<<endl;
             cout<<"END INDEX= "<<endIndex<<endl;

             cout<<"start_x:"<<a.getstorage().at(i).at(j).start_x<<"first sentence index: "<<a.get_filex_sentences_index()[i] <<endl;
             cout<<"index of word in the phrase: "<<a.getstorage().at(i).at(j).index_x;
             cout<<"start index: "<<startIndex<<endl;
             cout<<"end index: "<<endIndex<< endl;






        }
       }
    }
   /* for(int i=1;i<=a.number_of_phrases_filex();i++)
    {


            for(int j=0;j<a.getstorage().at(i).size();j++)
            {
                for(int k=0;k<a.getstorage().at(i).at(j).size();k++)
                {
                if(a.getstorage().at(i).at(j).at(k).index_x!=-999)
                {
                int startIndex=a.get_filex_sentences_index()[i-1]+a.getstorage().at(i).at(j).at(k).index_x;
                int endIndex=startIndex+a.getstorage().at(i).at(j).at(k).text.length();

                QString labelText = ui->label_5->text(); // get the text of label_2 widget


                // apply highlighting with span element and yellow background color to the specified section of text
                QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

                // combine the rest of the label text with the highlighted text
                QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

                ui->label_5->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
                ui->label_5->setText(finalText); // set the final text as the text of label_2 widget
                }
                }

            }

    }*/
}



void MainWindow::on_pushButton_4_clicked()
{
    QString labelText = ui->label_2->text(); // get the text of label_2 widget
    int startIndex = 2; // the start index of text to highlight
    int endIndex = 4; // the last index of text to highlight

    // apply highlighting with span element and yellow background color to the specified section of text
    QString highlightedText = "<span style='background-color: yellow'>" + labelText.mid(startIndex, endIndex - startIndex + 1) + "</span>";

    // combine the rest of the label text with the highlighted text
    QString finalText = labelText.left(startIndex) + highlightedText + labelText.right(labelText.length() - endIndex - 1);

    ui->label_2->setTextFormat(Qt::RichText); // set the text format of the widget to RichText
    ui->label_2->setText(finalText); // set the final text as the text of label_2 widget


}





void MainWindow::on_pushButton_5_clicked()
{



}

