#ifndef XML
#define XML

#include "designer.h" 

void XmlLoader_saveToString(char * str, const Designer * entity); 
void XmlLoader_loadFromString(Designer * entity, const char * xmlStr); 

#endif