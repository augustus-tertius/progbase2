#include <JsonLoader.h>
#include <jansson.h>
#include <string.h>

void JsonLoader_saveToString(char * str, const Designer * entity){
    json_t * designer = json_object();
    json_t * works = json_array();

    for(int i = 0; i < Designer_getQuan(entity); i++){
        Work* pWork = Designer_getWorkNumber(entity, i);
        json_t * work = json_object();

		json_object_set_new(work, "Workname", json_string(Work_getWorkName(pWork)));
		json_object_set_new(work, "year", json_integer(Work_getWorkYear(pWork)));
		json_array_append_new(works, work);
    }

	json_object_set_new(designer, "name", json_string(Designer_getName(entity)));
	json_object_set_new(designer, "age", json_integer(Designer_getAge(entity)));
	json_object_set_new(designer, "score", json_real(Designer_getScore(entity)));
    json_object_set_new(designer, "quan", json_integer(Designer_getQuan(entity)));
    json_object_set_new(designer, "works", works);
    
	char * jsonString = json_dumps(designer, JSON_INDENT(2));
    strcpy(str, jsonString);
	free(jsonString);

	json_decref(designer);
}

void JsonLoader_loadFromString(Designer * entity, const char * jsonString){
	json_error_t err;
	json_t * designer = json_loads(jsonString, 0, &err);

    char name [200] = "\0";
    strcpy(name, json_string_value(json_object_get(designer, "name"))); 
    Designer_setName(entity, name);

    Designer_setAge(entity, json_integer_value(json_object_get(designer, "age")));
    Designer_setScore(entity, json_real_value(json_object_get(designer, "score")));
    Designer_setQuan(entity, json_integer_value(json_object_get(designer, "quan")));

    json_t * works = json_object_get(designer, "works");
    int workInd = 0;
    int ind = 0;
    json_t * value = NULL;
	json_array_foreach(works, ind, value){
        Work* work = Designer_getWorkNumber(entity, workInd);

        char workName [100] = "\0";
        strcpy(workName, json_string_value(json_object_get(value, "workName"))); 
        Work_setWorkName(work, workName);

        Work_setWorkYear(work,json_integer_value(json_object_get(value, "year")));
        workInd++;
    }

    json_decref(designer);
}