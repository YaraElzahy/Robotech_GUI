#ifndef INTROWINDOW_H
#define INTROWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class IntroWindow;
}

class IntroWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit IntroWindow(QWidget *parent = nullptr);
    ~IntroWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::IntroWindow *ui;
    MainWindow *mainWindow;
};

#endif // INTROWINDOW_H
