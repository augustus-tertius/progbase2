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
void drawBox(struct menuBox box);
void printMainMenu(struct menuBox box);
void drawDownBox(struct menuBox box);
void pEnterOperationCode(struct menuBox box);
int printGB(struct menuBox box);
//void mainMenu(void);
List* startMenu(struct menuBox box, int* quan);
void drawStartMenu(struct menuBox box);
void drawFileInstructions (struct menuBox box);
void conFillEl(List* list, int index, struct menuBox box);
int conSaveToFile(struct menuBox box, List* list, int quan);
int conDeleteStruct(struct menuBox box, List* list, int quan);
int checkSrt(struct menuBox box, List* list);
void conEmptyStr(struct menuBox box);
void drawParametrsList(struct menuBox box);
void conRefillParam(struct menuBox box, List* list, int quan);
void conRefillStruct(struct menuBox box, List* list, int quan);
void conSearchStr(struct menuBox box, List* list, int quan);
void conStructToStr(struct menuBox box, List* head, int quan);

void freeAll(List* head);

#endif
