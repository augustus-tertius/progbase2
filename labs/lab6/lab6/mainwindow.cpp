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

     lectureCourse* toDelete = list.operator[](index);
     delete toDelete->getLecturer();
     delete toDelete;
     list.erase(list.begin()+index);

     this->on_listWidget_itemSelectionChanged();
}

void MainWindow::on_searchButton_clicked()
{
    int len = ui->lengthSpinBox->value();

    ui->resultsListWidget->clear();

    for(auto it = std::begin(this->list); it != std::end(this->list); it++){
        lectureCourse * cur = *it.base();

       if(cur->getLength() >= len){
           ui->resultsListWidget->addItem(cur->getCourseName());
       }
    }
}
