#include <stdio.h>
#include <string.h>

#include <jansson.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#include <lectureCourse.h>
#include <storage.h>

void readAllText(const char * filename, char * text) {
	char line[100] = "\0";
    
    FILE * fr = fopen(filename, "r");
    while(fgets(line, 100, fr)) {
        strcat(text, line);
    }

	fclose(fr);
}

int saveToFile(List* list, const char * FileName){
    FILE * fout = fopen(FileName, "w");
	if (fout == NULL){
        printf("Error opening file\n");
        return 0;
	}

    for(int i = 0; i < List_count(list); i++){
        LectureCourse* lC = List_get(list, i);
        char str [1000] = "\0";

        strcat(str,  LectureCourse_getCourseName(lC));
        strcat(str,  "\n");
        strcat(str,  LectureCourse_getLectSurname(lC));
        strcat(str,  " ");
        strcat(str,  LectureCourse_getLectName(lC));
        strcat(str,  " ");
        strcat(str,  LectureCourse_getLectMiddlen(lC));
        strcat(str,  " ");

        char buffer [50] = "\0"; 
        sprintf(buffer, "%i ", LectureCourse_getLectAge(lC));
        strcat(str,  buffer);
        sprintf(buffer, "%i ", LectureCourse_getLength(lC));
        strcat(str,  buffer);
        sprintf(buffer, "%.1f", LectureCourse_getRating(lC));
        strcat(str,  buffer);

        fprintf(fout, "%s\n", str);
    }

    fclose(fout);

    return 1;
}

List* readFromFile (int quan, const char * FileName) {
  FILE * fr = fopen(FileName, "r");
  if (fr == NULL){
    printf("Error opening file \n");
    return NULL;
  }

  List* list = List_new();

  char temp [5];
  for(int i = 0; i < quan && (!feof(fr)); i++){
    LectureCourse* LC = LectureCourse_new();

    char buf [300];
    fgets(buf, 300, fr);
    buf[strlen(buf) - 1] = '\0';
    LectureCourse_setCourseName(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectSurname(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectName(LC, buf);

    fscanf(fr, "%s", buf);
    LectureCourse_setLectMiddlen(LC, buf);

    int i = 0;

    fscanf(fr, "%i", &i);
    LectureCourse_setLectAge(LC, i);

    fscanf(fr, "%d", &i);
    LectureCourse_setLength(LC, i);

    float j = 0.0;
    fscanf(fr, "%f", &j);
    LectureCourse_setRating(LC, j);
    fgets(temp, 5, fr);

    List_add(list, LC);
  }

  fclose(fr);

  return list;
}

int Storage_writeAsXml(const char * filePath, List * list){
    char str [10000] = "\0";

    FILE * fout = fopen(filePath, "w");
	if (fout == NULL){
        printf("Error opening file\n");
        return 0;
	}

    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * lectureCourseNode = NULL;
	xmlNode * lecturerNode = NULL;

	char strBuf[100] = "\0";
	
	doc = xmlNewDoc(BAD_CAST "1.0");


	rootNode = xmlNewNode(NULL, BAD_CAST "lectureCourses");
	xmlDocSetRootElement(doc, rootNode);
	
    for(int i = 0; i < List_count(list); i++){
        LectureCourse* lC = List_get(list, i);

        lectureCourseNode = xmlNewChild(rootNode, NULL, BAD_CAST "lectureCourse", NULL);
        xmlNewChild(lectureCourseNode, NULL, BAD_CAST "courseName", BAD_CAST LectureCourse_getCourseName(lC));
        
        lecturerNode = xmlNewChild(lectureCourseNode, NULL, BAD_CAST "lecturer", NULL);
        xmlNewChild(lecturerNode, NULL, BAD_CAST "surname", BAD_CAST LectureCourse_getLectSurname(lC));
        xmlNewChild(lecturerNode, NULL, BAD_CAST "name", BAD_CAST LectureCourse_getLectName(lC));
        xmlNewChild(lecturerNode, NULL, BAD_CAST "middlen", BAD_CAST LectureCourse_getLectMiddlen(lC));
        sprintf(strBuf, "%i", LectureCourse_getLectAge(lC));
        xmlNewChild(lecturerNode, NULL, BAD_CAST "age", BAD_CAST strBuf);

        sprintf(strBuf, "%i", LectureCourse_getLength(lC));
        xmlNewChild(lectureCourseNode, NULL, BAD_CAST "length", BAD_CAST strBuf);
        sprintf(strBuf, "%.1f", LectureCourse_getRating(lC)); 
        xmlNewChild(lectureCourseNode, NULL, BAD_CAST "rating", BAD_CAST strBuf);
    }
    

	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);

	strcpy(str, (const char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
	
    xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();

    fprintf(fout, "%s", str);

    fclose(fout);
    return 1;
}

List * Storage_readAsXml(const char * filePath){
    char str [10000] = "\0";
    readAllText(filePath, str);
    List* list = List_new();

    xmlDoc * xDoc = xmlReadMemory(str, strlen(str), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return NULL;
    }
	 
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);
	for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
		if (XML_ELEMENT_NODE == xCur->type) {
            LectureCourse* lC = LectureCourse_new();
			for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
				if (XML_ELEMENT_NODE == xJ->type) {
					char * content = (char *)xmlNodeGetContent(xJ);
					if (xmlStrcmp(xJ->name, BAD_CAST "courseName") == 0) {
						 LectureCourse_setCourseName(lC, content);
					} else if (xmlStrcmp(xJ->name, BAD_CAST "lecturer") == 0) {
                        for (xmlNode * xLect = xJ->children; NULL != xLect ; xLect = xLect->next) {
                            if (XML_ELEMENT_NODE == xLect->type){
                                char * lcontent = (char *)xmlNodeGetContent(xLect);
                                if(xmlStrcmp(xLect->name, BAD_CAST "surname") == 0){
                                    LectureCourse_setLectSurname(lC, lcontent);
                                } else if(xmlStrcmp(xLect->name, BAD_CAST "name") == 0){
                                    LectureCourse_setLectName(lC, lcontent);
                                } else if(xmlStrcmp(xLect->name, BAD_CAST "middlen") == 0){
                                    LectureCourse_setLectMiddlen(lC, lcontent);
                                } else if(xmlStrcmp(xLect->name, BAD_CAST "age") == 0){
                                    LectureCourse_setLectAge(lC, atoi(lcontent));
                                }
                                xmlFree(lcontent);
                            }
                        }
                    } else if (xmlStrcmp(xJ->name, BAD_CAST "length") == 0) {
						LectureCourse_setLength(lC, atoi(content));
					} else if (xmlStrcmp(xJ->name, BAD_CAST "rating") == 0) {
						LectureCourse_setRating(lC, atof(content));
					}
					xmlFree(content);
				}
			}
            List_add(list, lC);
		}
	}

	xmlFreeDoc(xDoc);
	xmlCleanupParser();
	xmlMemoryDump();

    return list;
}




int Storage_writeAsJson(const char * filePath, List * list){
    char str [10000] = "\0";

    json_t * lectureCourses = json_array();

     for(int i = 0; i < List_count(list); i++){
         json_t * lectureCourse = json_object();    
         json_t * lecturer = json_object();

         LectureCourse* lC = List_get(list, i);

         json_object_set_new(lectureCourse, "courseName", json_string(LectureCourse_getCourseName(lC)));

         json_object_set_new(lecturer, "surname", json_string(LectureCourse_getLectSurname(lC)));
         json_object_set_new(lecturer, "name", json_string(LectureCourse_getLectName(lC)));
         json_object_set_new(lecturer, "middlen", json_string(LectureCourse_getLectMiddlen(lC)));
         json_object_set_new(lecturer, "age", json_integer(LectureCourse_getLectAge(lC)));
         json_object_set_new(lectureCourse, "lecturer", lecturer);

         json_object_set_new(lectureCourse, "length", json_integer(LectureCourse_getLength(lC)));
         json_object_set_new(lectureCourse, "rating", json_real(LectureCourse_getRating(lC)));

         json_array_append_new(lectureCourses, lectureCourse);
     }
    
	char * jsonString = json_dumps(lectureCourses, JSON_INDENT(2));
    strcpy(str, jsonString);
	free(jsonString);

	json_decref(lectureCourses);

    FILE * fout = fopen(filePath, "w");
	if (fout == NULL){
        printf("Error opening file\n");
        return 0;
	}

    fprintf(fout, "%s", str);

    fclose(fout);
    return 1;
}


List * Storage_readAsJson(const char * filePath){
    char str [10000] = "\0";
    readAllText(filePath, str);
    List* list = List_new();

    json_error_t err;
	json_t * lectureCourses = json_loads(str, 0, &err);

    int ind = 0;
    json_t * lectureCourse = NULL;
    json_array_foreach(lectureCourses, ind, lectureCourse){
        LectureCourse* lC = LectureCourse_new();

        char buf [300] = "\0";
        strcpy(buf, json_string_value(json_object_get(lectureCourse, "courseName")));
        LectureCourse_setCourseName(lC, buf);

        int length = json_integer_value(json_object_get(lectureCourse, "length"));
        LectureCourse_setLength(lC, length);

        float rating = json_real_value(json_object_get(lectureCourse, "rating"));
        LectureCourse_setLength(lC, rating);

        json_t * lecturer = json_object_get(lectureCourse, "lecturer");

        strcpy(buf, json_string_value(json_object_get(lecturer, "surname")));
        LectureCourse_setLectSurname(lC, buf);

        strcpy(buf, json_string_value(json_object_get(lecturer, "name")));
        LectureCourse_setLectName(lC, buf);

        strcpy(buf, json_string_value(json_object_get(lecturer, "middlen")));
        LectureCourse_setLectMiddlen(lC, buf);

        int age = json_integer_value(json_object_get(lecturer, "age"));
        LectureCourse_setLectAge(lC, age);

        List_add(list, lC);
    }

    json_decref(lectureCourses);

    return list;
}