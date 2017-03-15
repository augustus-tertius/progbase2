#include <stdlib.h>
#include <convert.h>
#include <string.h>
#include <stdio.h>

// void copyStruct (struct lectureCourse* newStr, struct lectureCourse* oldStr){
// //   strcpy(newStr->courseName, oldStr->courseName);
// //   strcpy(newStr->lecturer.surname, oldStr->lecturer.surname);
// //   strcpy(newStr->lecturer.name, oldStr->lecturer.name);
// //   strcpy(newStr->lecturer.middlen, oldStr->lecturer.middlen);

// //   newStr->lecturer.age = oldStr->lecturer.age;
// //   newStr->length = oldStr->length;
// //   newStr->rating = oldStr->rating;
// }

// // struct lectureCourse*  deleteStruct(struct lectureCourse* pArr, int* quan, int delnum){
// //   struct lectureCourse temp [*quan - 1];

// //   for(int i = 0; i < delnum - 1; i ++){
// //     copyStruct(&temp[i], &pArr[i]);
// //   }

// //   for(int i = delnum; i < *quan; i ++){
// //     copyStruct(&temp[i -1], &pArr[i]);
// //   }

// //   *quan = *quan - 1;

// //   pArr = (struct lectureCourse*) realloc(pArr, *(quan) * sizeof(struct lectureCourse));

// //   for(int i = 0; i < *quan && i != delnum + 1; i ++){
// //     copyStruct(&pArr[i], &temp[i]);
// //   }

// //   return pArr;
// // }

void refillParam(LectureCourse* lC, int line, char str [300]){
  int var = 0;

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
   char buffer [20] = "";
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