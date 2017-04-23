#include "mainwindow.h"
#include <QApplication>
#include "lecturecourse.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Lab 6");
    w.show();

    for(auto it = std::begin(w.list); it != std::end(w.list); it++){
        lectureCourse* cur = *it.base();
        delete cur->getLecturer();
        delete cur;
    }
    w.list.clear();

    return a.exec();
}
