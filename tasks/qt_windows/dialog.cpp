#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <iostream>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::Dialog(designer des, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle("Designer");

    QString age = QString::number(des.getAge());
    QString score = QString::number(des.getScore());

    ui->nameLabel->setText(des.getName());
    ui->ageLabel->setText(age);
    ui->scoreLabel->setText(score);
}

Dialog::~Dialog()
{
    delete ui;
}
