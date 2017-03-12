#include <designer.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Work{
    char workName [200];
    int year;
};

struct Designer {
    char name [100];
    int age;
    double score;
    int quan;
    Work works [10];
};

Designer* Designer_new(void){
    Designer* pDesigner = (Designer *) malloc(sizeof(Designer));
    if(NULL != pDesigner){
       strcpy( pDesigner->name, "\0");
       pDesigner->age = 0;
       pDesigner->score = 0.0;
       pDesigner->quan = 0;   
   }

   return pDesigner;
}

void Designer_free(Designer** self){
    free(*self);
    self = NULL;
}

const char* Work_getWorkName(const Work* self){
    return self->workName;
}

void Work_setWorkName(Work* self, char* buf){
    strcpy(self->workName, buf);
}


int Work_getWorkYear(const Work* self){
    return self->year;
}

void Work_setWorkYear(Work* self, int year){
    self->year = year;
}


const char* Designer_getName(const Designer* self){
    return self->name;
}

void Designer_setName(Designer* self, char* buf){
    strcpy(self->name, buf);
}


int Designer_getAge(const Designer* self){
    return self->age;
}

void Designer_setAge(Designer* self, int age){
    self->age = age;
}


double Designer_getScore(const Designer* self){
    return self->score;
}

void Designer_setScore(Designer* self, double score){
    self->score = score;
}

int Designer_getQuan(const Designer* self){
    return self->quan;
}
void Designer_setQuan(Designer* self, int quan){
    self->quan = quan;
}

void Designer_printData(Designer* self){
    printf("name: %s\n", self->name);
    printf("age: %i\n", self->age);
    printf("score: %.1f\n", self->score);
    printf("quan: %i\n", self->quan);

    for(int i = 0; i < self->quan; i++){
        printf("work # %i: %s, %i \n", i+1, self->works[i].workName, self->works[i].year);
    }

    printf("\n\n");
}


Work* Designer_getWorkNumber(const Designer* self, int number){
    if(self->quan >= number){
        return (Work*)&self->works[number];
    } else {
        return NULL;
    }
}