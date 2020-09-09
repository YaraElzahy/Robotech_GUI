#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <noteswindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    NotesWindow *notesWindow;

private slots:
    void changeTotal();
    void updateCountdown();
    void on_pushButton_timer_clicked();
    void on_radioButton1_clicked();
    void on_radioButton2_clicked();
    void on_radioButton3_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
};


#endif // MAINWINDOW_H
