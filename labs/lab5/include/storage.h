#include "list.h" 

#ifndef STORAGE
#define STORAGE

int saveToFile(List* head, const char * FileName);
List* readFromFile (int quan, const char * FileName);

int Storage_writeAsXml(const char * filePath, List * list);
List * Storage_readAsXml(const char * filePath);

int Storage_writeAsJson(const char * filePath, List * list);
List * Storage_readAsJson(const char * filePath);

#endif
