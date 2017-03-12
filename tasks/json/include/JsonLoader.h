#ifndef JSON
#define JSON

#include "designer.h" 

void JsonLoader_saveToString(char * str, const Designer * entity); 
void JsonLoader_loadFromString(Designer * entity, const char * jsonString); 

#endif