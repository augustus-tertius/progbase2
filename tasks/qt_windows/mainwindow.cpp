#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "designer.h"
#include <iostream>
#include <cstdlib>

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

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked){
        ui->nameEdit->setEnabled(true);
        ui->ageSpinBox->setEnabled(true);
        ui->scoreSpinBox->setEnabled(true);
    } else {
        ui->nameEdit->setEnabled(false);
        ui->ageSpinBox->setEnabled(false);
        ui->scoreSpinBox->setEnabled(false);
    }
}

void MainWindow::on_printButton_clicked()
{
    designer* des = new designer(ui->nameEdit->text(), ui->ageSpinBox->text().toInt(), ui->scoreSpinBox->value());

    Dialog* dialog = new Dialog(*des);
    dialog->setWindowTitle("Designer");

    dialog->exec();

}
