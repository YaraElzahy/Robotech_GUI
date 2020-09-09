#ifndef NOTESWINDOW_H
#define NOTESWINDOW_H

#include <QMainWindow>

namespace Ui {
class NotesWindow;
}

class NotesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotesWindow(QWidget *parent = nullptr);
    ~NotesWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::NotesWindow *ui;
    QString file_path;
};

#endif // NOTESWINDOW_H
