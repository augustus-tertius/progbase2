#ifndef DESIGN
#define DESIGN

typedef struct Work Work;
typedef struct Designer Designer;

Designer* Designer_new(void);
void Designer_free(Designer** self);
Designer* Designer_create();

const char* Work_getWorkName(const Work* self);
int Work_getWorkYear(const Work* self);

void Work_setWorkName(Work* self, char* buf);
void Work_setWorkYear(Work* self, int year);


const char* Designer_getName(const Designer* self);
void Designer_setName(Designer* self, char* buf);

int Designer_getAge(const Designer* self);
void Designer_setAge(Designer* self, int age);

double Designer_getScore(const Designer* self);
void Designer_setScore(Designer* self, double score);

int Designer_getQuan(const Designer* self);
void Designer_setQuan(Designer* self, int quan);

void Designer_printData(Designer* self);

Work* Designer_getWorkNumber(const Designer* self, int number);

#endif