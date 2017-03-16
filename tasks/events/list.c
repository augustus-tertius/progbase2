#include "list.h" 
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define throw(MSG) assert(0 && MSG);

struct List {
    size_t capacity;
    size_t size;
    void ** items;    /**< holds a pointer to items array */
};

static const int initialCapacity = 4;

static void __ensureCapacity(List * self, size_t min);

List * List_new(void) {
    List * self = malloc(sizeof(struct List));
    self->capacity = initialCapacity;
    self->size = 0;
    self->items = malloc(0);
    __ensureCapacity(self, 0);
    return self;
}

void List_free(List ** selfPtr) {
    if (selfPtr == NULL) throw("Null pointer on free()");
    List * self = *selfPtr;

    free(self->items);
    free(self);
    *selfPtr = NULL;
}

void List_freeAll(void * self){
    for(int i = 0; i < ((List*)self)->size; i++){
        free(List_get(self, i));
    }
    List_free((List**)&(self));
}

void* List_get(List * self, int index) {
    if (index < 0 || index >= self->size) throw("Index out of bounds");
    return self->items[index];
}

void List_set(List * self, int index, void * ref) {
    if (ref == NULL) throw("NULL reference");
    if (index < 0 || index >= self->size) throw("Index out of bounds");
    self->items[index] = ref;
}

void List_add(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    if (self->size <= self->capacity) {
        __ensureCapacity(self, self->size + 1);
    }
    List_set(self, self->size++, ref);
}

int List_indexOf(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    for (int i = 0; i < self->size; i++) {
        if (self->items[i] == ref) {
            return i;
        }
    }
    return -1;
}

int List_remove(List * self, void * ref) {
    if (ref == NULL) throw("NULL reference");
    int index = List_indexOf(self, ref);
    if (index >= 0) {
        List_removeAt(self, index);
        return 0;
    }
    return 1;
}

void List_removeAt(List * self, int index) {
    if (index < 0 || index >= self->size) throw("Index out of bounds");

    free(List_get(self,index));
    
    (self->size)--;

    if (index < self->size) {
        for(int i = index; i < self->size; i++){
            self->items[i] = self->items[i + 1];
        }
    }


}

int List_isEmpty(List * self) {
    return self->size == 0;
}

int  List_count(List * self) {
    return self->size;
}

static void __ensureCapacity(List * self, size_t min) {
    if (self->size <= min) {
        int newCapacity = self->size == 0 ? initialCapacity : self->size * 2;
        if (newCapacity < min) newCapacity = min;
        self->capacity = newCapacity;
        size_t newSize = sizeof(void *) * self->capacity;
        self->items = realloc(self->items, newSize);
    }
}

int List_getSize(List* self){
    return self->size;
}

void List_print(List* self){
    for(int i = 0; i < self->size; i++){
        printf("  ID%i,", *((int*)List_get(self, i)));
    }
}