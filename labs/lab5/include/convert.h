#ifndef CONVERT
#define CONVERT

#include "lectureCourse.h"
#include "list.h" 

void copyStruct (struct lectureCourse* newStr, struct lectureCourse* oldStr);
int searchStr(List* list, int quan, int x, struct lectureCourse* res[]);
void refillParam(LectureCourse* lC, int line, char str [300]);
char* structToStr(LectureCourse* lC, char str [1000]);

#endif