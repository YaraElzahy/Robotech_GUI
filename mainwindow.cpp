#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include <qdebug.h>
#include <QTimer>
#include <QTime>
#include <windows.h>
#include <QPalette>
#include <QFile>
#include <QElapsedTimer>
#include <QDateTime>

using namespace std;

int totalPoints = 0;
QTimer *timer;
QTime *t = new QTime(0, 5, 0);
map <string, int> points;
QElapsedTimer elapsedTime;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /* Mission Points tab  */
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(totalPoints));
    QCheckBox *checkBox[16];

    for(int i = 0; i < 16; ++i){
      QString checkBoxName = "checkBox" + QString::number(i);
      checkBox[i] = MainWindow::findChild<QCheckBox*>(checkBoxName);
      connect(checkBox[i], SIGNAL(toggled(bool)), this, SLOT(changeTotal()));
    }

    /* System Monitor tab  */
    ui->countdownTimer->setText("5:00");  // initialize timer text


    // connect timer to slot so it gets updated
    t->setHMS(0, 5, 0);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));

    // set default mode
    ui->radioButton1->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeTotal(){
    QCheckBox *box = (QCheckBox*)sender();
    QString pointsVal = box->text();
   // qDebug() << pointsVal;
   //std::cout << pointsVal.toStdString();

    if(box->isChecked()){
        string mystr = pointsVal.toStdString();
        size_t dashIndex = mystr.find('-');

        string substring = mystr.substr(dashIndex);
        string num = "";

            for(int i = (int)dashIndex + 2; mystr[i] != ' '; i++){
              num += mystr[i];
            }
            int number = stoi(num);
            totalPoints += number;
            ui->lineEdit->setText(QString::number(totalPoints));
            points[box->text().toStdString()] = elapsedTime.elapsed();
    }
    if(box->checkState() == false){
        string mystr = pointsVal.toStdString();
        size_t dashIndex = mystr.find('-');

        string substring = mystr.substr(dashIndex);
        string num = "";

            for(int i = (int)dashIndex + 2; mystr[i] != ' '; i++){
              num += mystr[i];
            }
            int number = stoi(num);
            totalPoints -= number;
            ui->lineEdit->setText(QString::number(totalPoints));
            points.erase(box->text().toStdString());
    }

}
void MainWindow::updateCountdown(){

  *t = t->addSecs(-1);
  ui->countdownTimer->setText(t->toString("m:ss"));
 // Beep(400, 500);
  if ((t->minute() >= 1 && t->second() == 0)){
    Beep(400, 500);
  }
  if((t->minute() == 0 && t->second() <= 30 )){
      Beep(400, 500);
      ui->countdownTimer->setStyleSheet("QLineEdit {color: red;}");
  }
  if(t->minute() == 0 && t->second() == 0){
     timer->stop();
  }
}



void MainWindow::on_pushButton_timer_clicked()
{    ui->countdownTimer->setStyleSheet("QLineEdit {color: black;}");
    t->start();
    t->setHMS(0, 5, 0);
    elapsedTime.start();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCountdown()));
    timer->start(1000);
}

void MainWindow::on_radioButton1_clicked()
{
    ui->lineEdit_Mode->setText("1");
}

void MainWindow::on_radioButton2_clicked()
{
    ui->lineEdit_Mode->setText("2");
}

void MainWindow::on_radioButton3_clicked()
{
    ui->lineEdit_Mode->setText("3");
}

void MainWindow::on_pushButton_5_clicked()
{
   notesWindow = new NotesWindow(this);
   notesWindow->show();
}

void MainWindow::on_pushButton_clicked()
{
    notesWindow = new NotesWindow(this);
    notesWindow->show();
}
multimap<int, string> invert(map<string, int> & mymap)
{
    multimap<int, string> multiMap;

    map<string, int> :: iterator it;
    for (it=mymap.begin(); it!=mymap.end(); it++)
    {
        multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;
}

void MainWindow::on_pushButton_6_clicked()
{
    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd_hh-mm-ss");
    QString fname = "file_" + dateTimeString + ".txt";
    QFile file(fname);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "cannot open file!");
        return;
    }
    QTextStream out(&file);
    // invert mymap using the invert function created above
    multimap<int, string> newmap = invert(points);
    for (auto i = newmap.begin(); i != newmap.end(); i++) {
            string fileContent = to_string((i->first)/1000) +" seconds" + " : " + i->second.c_str() + "\n";
            file.write(fileContent.c_str());
        }

    file.flush();
    file.close();
}
// Function to convert a map<key,value> to a multimap<value,key>

