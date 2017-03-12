#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <xmlLoader.h>


void readAllText(const char * filename, char * text);

int main(void){
    
    char text [1000] = "\0";
    readAllText("designer.xml", text);

    Designer* pDesigner = Designer_new();

    XmlLoader_loadFromString(pDesigner, text);
    printf("\nDesigner data from xml string: \n\n");
    Designer_printData(pDesigner);

    puts("---//---");

    char buf [1000] = "/0";
    XmlLoader_saveToString(buf, pDesigner);
    printf("\n\nXml string from designer entity: \n\n");
    puts(buf);

    Designer_free(&pDesigner);
    return 0;
}

void readAllText(const char * filename, char * text) {
	char line[100];
    
    FILE * fr = fopen(filename, "r");
    while(fgets(line, 100, fr)) {
        strcat(text, line);
    }
	fclose(fr);
}
