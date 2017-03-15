#include "list.h" 

#ifndef STORAGE
#define STORAGE

int saveToFile(List* head, const char * FileName);
List* readFromFile (int quan, const char * FileName);

#endif
