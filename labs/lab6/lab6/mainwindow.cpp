#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "lecturer.h"
#include "lecturecourse.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    Dialog* dialog = new Dialog(0);
    dialog->setWindowTitle("Create a new lecture course");

    if(dialog->exec()){
//        QVariant qVariant;
//        qVariant.setValue(*lc);

//        QListWidgetItem *item = new QListWidgetItem();
//        item->setText(lc->getCourseName());
//        item->setData(Qt::UserRole, qVariant);

//        ui->listWidget->addItem(item);
        lectureCourse * lc = dialog->getData();
        this->list.push_back(lc);
        ui->listWidget->addItem(lc->getCourseName());
    }

}

void MainWindow::on_listWidget_itemSelectionChanged()
{
    qDebug() << "changed!";
    auto items = ui->listWidget->selectedItems();
    auto hasSelected = items.size() > 0;
    ui->removeButton->setEnabled(hasSelected);

    if(hasSelected){
        lectureCourse* selected = this->list.operator[](ui->listWidget->row(items[0]));

        ui->courseNameLabel->setText(selected->getCourseName());
        ui->lengthLabel->setText(QString::number(selected->getLength()));
        ui->ratinglabel->setText(QString::number(selected->getRating()));

        lecturer* curLec = selected->getLecturer();

        ui->lectNameLabel->setText(curLec->getName());
        ui->lectSurnameLabel->setText(curLec->getSurname());
        ui->lectMiddlenLabel->setText(curLec->getMiddlen());
        ui->lectAgeLabel->setText(QString::number(curLec->getAge()));
    } else {
        ui->courseNameLabel->setText("");
        ui->lengthLabel->setText("");
        ui->ratinglabel->setText("");
        ui->lectNameLabel->setText("");
        ui->lectSurnameLabel->setText("");
        ui->lectMiddlenLabel->setText("");
        ui->lectAgeLabel->setText("");
    }
}

void MainWindow::on_removeButton_clicked()
{
     auto items = ui->listWidget->selectedItems();
     int index = ui->listWidget->row(items[0]);

     delete ui->listWidget->takeItem(index);
     delete list.operator[](index);
     list.erase(list.begin()+index);

     this->on_listWidget_itemSelectionChanged();
}
