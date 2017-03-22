#define CUI
#ifdef CUI

#include "list.h"
#include "lectureCourse.h" 

struct menuBox {
  int top;
  int bottom;
  int left;
  int right;
  int head;
  int down;
};

void drawBg (void);
void drawBox(void);
void printMainMenu(void);
void drawDownBox(void);
void pEnterOperationCode(void);
void printMessage(char* str);
int printGB(void);
void drawStartMenu(void);
void drawParametrsList(void);

List* startMenu(int* quan);
void conFillEl(List* list, int index);
int conSaveToFile(List* list, int quan);
int conDeleteStruct(List* list, int quan);
int checkSrt(List* list);
void conEmptyStr(void);
void conRefillParam(List* list, int quan);
void conRefillStruct(List* list, int quan);
void conSearchStr(List* list, int quan);
void conStructToStr(List* head, int quan);

void freeAll(List* head);





#endif
