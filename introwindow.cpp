#include "introwindow.h"
#include "ui_introwindow.h"
#include <QPixmap>

IntroWindow::IntroWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IntroWindow)
{
    ui->setupUi(this);
       QPixmap bkgnd(":/rec/6ba7cd81a0bef63d482a8f7a0e5fc6cd.jpg");
      // bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);
   // this->centralWidget()->setStyleSheet("background-image:url(\":/rec/6ba7cd81a0bef63d482a8f7a0e5fc6cd.jpg\"); background-position: center;");
}

IntroWindow::~IntroWindow()
{
    delete ui;
}


void IntroWindow::on_pushButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->show();
}
