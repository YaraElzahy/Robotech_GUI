#include "notesform.h"
#include "ui_notesform.h"

NotesForm::NotesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotesForm)
{
    ui->setupUi(this);
}

NotesForm::~NotesForm()
{
    delete ui;
}
