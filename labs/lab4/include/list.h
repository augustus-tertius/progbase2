#ifndef LIST
#define LIST

#include <stdlib.h>

typedef struct List List;

List * List_new(void);
void List_free(List ** self);
void* List_get(List * self, int index);
void List_set(List * self, int index, void * ref);
void List_add(List * self, void * ref);
int List_indexOf(List * self, void * ref);
int List_remove(List * self, void * ref);
void List_removeAt(List * self, int index);
int List_isEmpty(List * self);
int  List_count(List * self);
int  List_indexOf(List * self, void * ref);
int List_getSize(List* self);

#endif 