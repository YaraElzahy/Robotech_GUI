#ifndef NOTESFORM_H
#define NOTESFORM_H

#include <QWidget>

namespace Ui {
class NotesForm;
}

class NotesForm : public QWidget
{
    Q_OBJECT

public:
    explicit NotesForm(QWidget *parent = nullptr);
    ~NotesForm();

private:
    Ui::NotesForm *ui;
};

#endif // NOTESFORM_H
