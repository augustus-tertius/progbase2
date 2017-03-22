#include <stdlib.h>
#include <convert.h>
#include <string.h>
#include <stdio.h>

void copyStruct (struct lectureCourse* newStr, struct lectureCourse* oldStr){

  if(newStr == NULL || oldStr == NULL){
    return;
  }

  LectureCourse_setCourseName(newStr, LectureCourse_getCourseName(oldStr));

  LectureCourse_setLectSurname(newStr, LectureCourse_getLectSurname(oldStr));
  LectureCourse_setLectName(newStr, LectureCourse_getLectName(oldStr));
  LectureCourse_setLectMiddlen(newStr, LectureCourse_getLectMiddlen(oldStr));
  LectureCourse_setLectAge(newStr, LectureCourse_getLectAge(oldStr));

  LectureCourse_setLength(newStr, LectureCourse_getLength(oldStr));
  LectureCourse_setRating(newStr, LectureCourse_getRating(oldStr));
}


void refillParam(LectureCourse* lC, int line, char str [300]){
  int var = 0;

  if(str == NULL) return;

  switch(line){
    case 1:
      LectureCourse_setCourseName(lC, str);
      break;
    case 2:
      LectureCourse_setLectSurname(lC, str);
      break;
    case 3:
      LectureCourse_setLectName(lC, str);
      break;
    case 4:
      LectureCourse_setLectMiddlen(lC, str);
      break;
    case 5:
      var = atoi(str);
      LectureCourse_setLectAge(lC, var);
      break;
    case 6:
      var = atoi(str);
      LectureCourse_setLength(lC, var);
      break;
    case 7:
      var = atof(str);
      LectureCourse_setRating(lC, var);
      break;
  }
}

int searchStr(List* list, int quan, int x, struct lectureCourse* res[]){
  int count = 0;

  for(int i = 0; i < quan; i++){
    LectureCourse * lC = List_get(list, i);
    if(LectureCourse_getLength(lC) > x) {
      res[count] = lC;
      count++;
    }
  }

  return count;
}

 char* structToStr(struct lectureCourse* lC, char str [1000]){
   char buffer [20] = "\0";
   str[0] = '\0';

   if(lC == NULL){
     return str;
   }


   strcat(str,  LectureCourse_getCourseName(lC));
   strcat(str,  " ");
   strcat(str,  LectureCourse_getLectSurname(lC));
   strcat(str,  " ");
   strcat(str,  LectureCourse_getLectName(lC));
   strcat(str,  " ");
   strcat(str,  LectureCourse_getLectMiddlen(lC));
   strcat(str,  " ");

   sprintf(buffer, "%i ", LectureCourse_getLectAge(lC));
   strcat(str,  buffer);
   sprintf(buffer, "%i ", LectureCourse_getLength(lC));
   strcat(str,  buffer);
   sprintf(buffer, "%.1f", LectureCourse_getRating(lC));
   strcat(str,  buffer);

   return str;
 }