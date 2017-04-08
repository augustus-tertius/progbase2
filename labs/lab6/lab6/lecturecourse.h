#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "lecturer.h"
#include <QString>


class lectureCourse
{
    QString courseName;
    int length;
    double rating;
    lecturer* lec;

public:
    lectureCourse();
    lectureCourse(QString courseName,
                  int length,
                  double rating,
                  QString lecName,
                  QString lecSurname,
                  QString lecMiddlen,
                  int lecAge);

    void setCourseName(QString courseName);
    void setLength(int length);
    void setRating(double rating);
    void setLecturer(lecturer* lect);

    QString getCourseName();
    int getLength();
    double getRating();
    lecturer* getLecturer();
};

#endif // LECTURECOURSE_H
