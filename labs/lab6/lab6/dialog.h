#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QList>
#include <lecturecourse.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    lectureCourse* getData();
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
