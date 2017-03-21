#ifndef L_COURSE
#define L_COURSE

typedef struct lecturer Lecturer;
typedef struct lectureCourse LectureCourse;

LectureCourse* LectureCourse_new(void);
void LectureCourse_free(LectureCourse ** self);
LectureCourse* LectureCourse_create(
    char cName [300], 
    char LecSN [100], 
    char LecN [100], 
    char LecM [100],
    int LecA, 
    int length,
    float rating);

void LectureCourse_setCourseName(LectureCourse* self, char cName [300]);
void LectureCourse_setLectSurname (LectureCourse* self, char LecSN [100]);
void LectureCourse_setLectName (LectureCourse* self, char LecN [100]);
void LectureCourse_setLectMiddlen (LectureCourse* self, char LecM [100]);
void LectureCourse_setLectAge (LectureCourse* self, int LecA);
void LectureCourse_setLength(LectureCourse* self, int length);
void LectureCourse_setRating(LectureCourse* self, float rating);

char* LectureCourse_getCourseName(LectureCourse* self);
char* LectureCourse_getLectSurname (LectureCourse* self);
char* LectureCourse_getLectName (LectureCourse* self);
char* LectureCourse_getLectMiddlen (LectureCourse* self);
int LectureCourse_getLectAge (LectureCourse* self);
int LectureCourse_getLength(LectureCourse* self);
float LectureCourse_getRating(LectureCourse* self);

#endif