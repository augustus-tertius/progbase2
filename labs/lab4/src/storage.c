#include <stdio.h>
#include <string.h>

#include <lectureCourse.h>
#include <storage.h>

int saveToFile(List* list, const char * FileName){
    FILE * fout = fopen(FileName, "w");
	if (fout == NULL){
    printf("Error opening file\n");
    return 0;
	}

    for(int i = 0; i < List_getSize(list); i++){
        LectureCourse* lC = List_get(list, i);
        char str [1000] = "\0";

        strcat(str,  LectureCourse_getCourseName(lC));
        strcat(str,  "\n");
        strcat(str,  LectureCourse_getLectSurname(lC));
        strcat(str,  " ");
        strcat(str,  LectureCourse_getLectName(lC));
        strcat(str,  " ");
        strcat(str,  LectureCourse_getLectMiddlen(lC));
        strcat(str,  " ");

        char buffer [50] = "\0"; 
        sprintf(buffer, "%i ", LectureCourse_getLectAge(lC));
        strcat(str,  buffer);
        sprintf(buffer, "%i ", LectureCourse_getLength(lC));
        strcat(str,  buffer);
        sprintf(buffer, "%.1f", LectureCourse_getRating(lC));
        strcat(str,  buffer);

        fprintf(fout, "%s\n", str);
    }

    fclose(fout);

    return 1;
}

List* readFromFile (int quan, const char * FileName) {
  FILE * fr = fopen(FileName, "r");
  if (fr == NULL){
    printf("Error opening file \n");
    return NULL;
  }

  List* list = List_new();

  char temp [5];
  for(int i = 0; i < quan && (!feof(fr)); i++){
    LectureCourse* LC = LectureCourse_new();

    char buf [300];
    fgets(buf, 300, fr);
    buf[strlen(buf) - 1] = '\0';
    LectureCourse_setCourseName(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectSurname(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectName(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectMiddlen(LC, buf);

    int i = 0;

    fscanf(fr, "%i", &i);
    LectureCourse_setLectAge(LC, i);

    fscanf(fr, "%d", &i);
    LectureCourse_setLength(LC, i);

    float j = 0.0;
    fscanf(fr, "%f", &j);
    LectureCourse_setRating(LC, j);
    fgets(temp, 5, fr);

    List_add(list, LC);
  }

  fclose(fr);

  return list;
}