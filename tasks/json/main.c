#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <JsonLoader.h>

void readAllText(const char * filename, char * text);

int main(void){

    char text [1000] = "\0";
    readAllText("designer.json", text);

    Designer* pDesigner = Designer_new();

    JsonLoader_loadFromString(pDesigner, text);
    printf("\nDesigner data from json string: \n\n");

    Designer_printData(pDesigner);
    
    puts("---//---");

    char buf [1000] = "/0";
    JsonLoader_saveToString(buf, pDesigner);
    printf("\n\nJson string from designer entity: \n\n");
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