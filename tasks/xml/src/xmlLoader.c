#include <xmlLoader.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>

void XmlLoader_saveToString(char * str, const Designer * entity){
    xmlDoc * doc = NULL;
	xmlNode * rootNode = NULL;
	xmlNode * designerNode = NULL;
	xmlNode * worksNode = NULL;
    xmlNode * workNode = NULL;
	char strBuf[100];
	
	doc = xmlNewDoc(BAD_CAST "1.0");


	rootNode = xmlNewNode(NULL, BAD_CAST "designers");
	xmlDocSetRootElement(doc, rootNode);
	
	designerNode= xmlNewChild(rootNode, NULL, BAD_CAST "designer", NULL);
	xmlNewChild(designerNode, NULL, BAD_CAST "name", BAD_CAST Designer_getName(entity));

    sprintf(strBuf, "%i", Designer_getAge(entity));
    xmlNewChild(designerNode, NULL, BAD_CAST "age", BAD_CAST strBuf);
	sprintf(strBuf, "%.1f", Designer_getScore(entity)); 
	xmlNewChild(designerNode, NULL, BAD_CAST "score", BAD_CAST strBuf);
    

	worksNode = xmlNewChild(designerNode, NULL, BAD_CAST "works", NULL);
	sprintf(strBuf, "%i", Designer_getQuan(entity));
	xmlNewProp(worksNode, BAD_CAST "quan", BAD_CAST strBuf);
	for(int i = 0; i < Designer_getQuan(entity); i++){
		const Work* cur = Designer_getWorkNumber(entity, i);
		if(cur != NULL){
            workNode = xmlNewChild(worksNode, NULL, BAD_CAST "work", NULL);
			xmlNewChild(workNode, NULL, BAD_CAST "workName", BAD_CAST Work_getWorkName(cur));
			sprintf(strBuf, "%i", Work_getWorkYear(cur));
			xmlNewChild(workNode, NULL, BAD_CAST "year", BAD_CAST strBuf);
		}
	}
	

	xmlBuffer * bufferPtr = xmlBufferCreate();
	xmlNodeDump(bufferPtr, NULL, (xmlNode *)doc, 0, 1);

	strcpy(str, (const char *)bufferPtr->content);
	xmlBufferFree(bufferPtr);
	
    xmlFreeDoc(doc);
	xmlCleanupParser();
	xmlMemoryDump();
}

void XmlLoader_loadFromString(Designer * entity, const char * xmlStr){

	xmlDoc * xDoc = xmlReadMemory(xmlStr, strlen(xmlStr), NULL, NULL, 0);
    if (NULL == xDoc) {
        printf("Error parsing xml");
        return;
    }
	 
    xmlNode * xRootEl = xmlDocGetRootElement(xDoc);

	for(xmlNode * xCur = xRootEl->children; NULL != xCur ; xCur = xCur->next) {
		if (XML_ELEMENT_NODE == xCur->type) {
			for (xmlNode * xJ = xCur->children; NULL != xJ ; xJ = xJ->next) {
				if (XML_ELEMENT_NODE == xJ->type) {
					char * content = (char *)xmlNodeGetContent(xJ);
					if (xmlStrcmp(xJ->name, BAD_CAST "works") == 0) {
						xmlNode * xWorks = xJ;

						char * quan = (char *)xmlGetProp(xWorks, BAD_CAST "quan");
						Designer_setQuan(entity, atoi(quan));
						xmlFree(quan);

						int worksQuan = 0;
						for(xmlNode * xK = xWorks->children; NULL != xK ; xK = xK->next){
							if (XML_ELEMENT_NODE == xK->type){
								Work* pWork = Designer_getWorkNumber(entity, worksQuan);

								for(xmlNode * xM = xK->children; NULL != xM; xM = xM->next){
									if(XML_ELEMENT_NODE == xM->type){
										char * wContent = (char *)xmlNodeGetContent(xM);

										if(xmlStrcmp(xM->name, BAD_CAST "workName") == 0){
											Work_setWorkName(pWork, wContent);
										} else if(xmlStrcmp(xM->name, BAD_CAST "year") == 0){
											Work_setWorkYear(pWork, atoi(wContent));
										}

										xmlFree(wContent);
									}
								}
								worksQuan++;
							}
						}

					}
					if (xmlStrcmp(xJ->name, BAD_CAST "name") == 0) {
						Designer_setName(entity, content);
					} else if (xmlStrcmp(xJ->name, BAD_CAST "age") == 0) {
						Designer_setAge(entity, atoi(content));
					} else if (xmlStrcmp(xJ->name, BAD_CAST "score") == 0) {
						Designer_setScore(entity, atof(content));
					}
					xmlFree(content);
				}
			}
		}
	}

	xmlFreeDoc(xDoc);
	xmlCleanupParser();
	xmlMemoryDump();
}