#include "noteswindow.h"
#include "ui_noteswindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

NotesWindow::NotesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NotesWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

NotesWindow::~NotesWindow()
{
    delete ui;
}

void NotesWindow::on_actionNew_triggered()
{
   file_path = "";
   ui->textEdit->setText("");
}

void NotesWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void NotesWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void NotesWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void NotesWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void NotesWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void NotesWindow::on_actionOpen_triggered()
{
   QString file_name = QFileDialog::getOpenFileName(this,"open the file");
   QFile file(file_name);
   file_path = file_name;
   if(!file.open(QFile::ReadOnly | QFile::Text)){
       QMessageBox::warning(this, "..", "cannot open file!");
       return;
   }
   QTextStream in(&file);
   QString text = in.readAll();
   ui->textEdit->setText(text);
   file.close();
}

void NotesWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "cannot open file!");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void NotesWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this,"open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "cannot open file!");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}
