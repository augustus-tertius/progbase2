#include "lecturecourse.h"

lectureCourse::lectureCourse(){
    this->courseName = "";
    this->rating = 0;
    this->length = 0;
    this->lec = new lecturer();
}

lectureCourse::lectureCourse(QString courseName, int length, double rating, QString lecName, QString lecSurname, QString lecMiddlen, int lecAge)
{
    this->courseName = courseName;
    this->rating = rating;
    this->length = length;
    this->lec = new lecturer(lecName, lecSurname, lecMiddlen, lecAge);
}

void lectureCourse::setCourseName(QString courseName){
    this->courseName = courseName;
}

void lectureCourse::setLength(int length){
    this->length = length;
}

void lectureCourse::setRating(double rating){
    this->rating = rating;
}

void lectureCourse::setLecturer(lecturer* lect){
    this->lec = lect;
}

QString lectureCourse::getCourseName(){
    return this->courseName;
}

int lectureCourse::getLength(){
    return this->length;
}

double lectureCourse::getRating(){
    return this->rating;
}

lecturer* lectureCourse::getLecturer(){
    return this->lec;
}
