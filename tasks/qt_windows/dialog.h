#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "designer.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    Dialog(designer des = {"", 0, 0}, QWidget *parent = 0);
    ~Dialog();


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
