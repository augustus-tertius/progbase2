#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <lectureCourse.h>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::vector <lectureCourse*> list;

private slots:
    void on_addButton_clicked();

    void on_listWidget_itemSelectionChanged();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_removeButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
