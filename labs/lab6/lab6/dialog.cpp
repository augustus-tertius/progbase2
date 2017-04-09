#include "dialog.h"
#include "ui_dialog.h"
#include <lecturecourse.h>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

lectureCourse* Dialog::getData(){
        QString courseName = ui->courseNameEdit->text();
        int length = ui->lengthSpinBox->value();
        double rating = ui->ratingSpinBox->value();
        QString lecName = ui->lectNameEdit->text();
        QString lecSurname = ui->lectSurnameEdit->text();
        QString lecMiddlen = ui->lectMiddlenEdit->text();
        int lecAge = ui->lectAgeSpinBox->value();

        lectureCourse* lc = new lectureCourse(courseName, length, rating, lecName, lecSurname, lecMiddlen, lecAge);
        return lc;
}


Dialog::~Dialog()
{
    delete ui;
}


