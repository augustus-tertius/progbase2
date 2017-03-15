#include <stdlib.h>
#include <string.h>
#include <lectureCourse.h>

struct lecturer {
  char surname [100];
  char name [100];
  char middlen [100];
  int age;
};

struct lectureCourse {
  char courseName [300];
  Lecturer lecturer;
  int length; // тривалість курсу лекцій
  float rating; // оцінка курсу
};

LectureCourse* LectureCourse_new(void){
    LectureCourse* pLC = (LectureCourse *) malloc(sizeof(LectureCourse));
    return pLC;
}

void LectureCourse_free(LectureCourse ** self){
    free(*self);
    self = NULL;
}

LectureCourse* LectureCourse_create(char cName [300], char LecSN [100], char LecN [100], char LecM [100], 
int LecA, int length, float rating){
    LectureCourse * LC = LectureCourse_new();

    strcpy(LC->courseName, cName);
    strcpy(LC->lecturer.surname, LecSN);
    strcpy(LC->lecturer.name, LecN);
    strcpy(LC->lecturer.middlen, LecM);
    LC->lecturer.age = LecA;
    LC->length = length;
    LC->rating = rating;
    
    return LC;
}

void LectureCourse_setCourseName(LectureCourse* self, char cName [300]){
    strcpy(self->courseName, cName);
}

void LectureCourse_setLectSurname (LectureCourse* self, char LecSN [100]){
    strcpy(self->lecturer.surname, LecSN);
}

void LectureCourse_setLectName (LectureCourse* self, char LecN [100]){
     strcpy(self->lecturer.name, LecN);
}

void LectureCourse_setLectMiddlen (LectureCourse* self, char LecM [100]){
    strcpy(self->lecturer.middlen, LecM);
}

void LectureCourse_setLectAge (LectureCourse* self, int LecA){
    self->lecturer.age = LecA;
}

void LectureCourse_setLength(LectureCourse* self, int length){
    self->length = length;
}

void LectureCourse_setRating(LectureCourse* self, float rating){
    self->rating = rating;
}

char* LectureCourse_getCourseName(LectureCourse* self){
    return self->courseName;
}

char* LectureCourse_getLectSurname (LectureCourse* self){
    return self->lecturer.surname;
}

char* LectureCourse_getLectName (LectureCourse* self){
    return self->lecturer.name;
}

char* LectureCourse_getLectMiddlen (LectureCourse* self){
    return self->lecturer.middlen;
}

int LectureCourse_getLectAge (LectureCourse* self){
    return self->lecturer.age;
}

int LectureCourse_getLength(LectureCourse* self){
    return self->length;
}

float LectureCourse_getRating(LectureCourse* self){
    return self->rating;
}






