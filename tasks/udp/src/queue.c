#include <queue.h>
#include <list.h>
#include <stdio.h>

struct Queue {
    List* l;
};

Queue* Queue_new(void){
    Queue* self = malloc(sizeof(Queue));
    self->l = List_new();

    return self;
}

void Queue_free(Queue ** self){
    for(int i = 0; i < List_count((*self)->l); i++){
        free(List_get((*self)->l, i));
    }
    List_free(&((*self)->l));
    free(&self);
}

void * Queue_getAt(Queue * self, int index){
    printf("requested str in position %i is %s\n", index, List_get(self->l, index));
    return List_get(self->l, index);
}

void Queue_add(Queue * self, void * ref){
    List_add(self->l, ref);
}

int Queue_removeFirst(Queue * self){
    if(!List_isEmpty(self->l)){
        free(List_get(self->l, 0));
        List_removeAt(self->l, 0);
        return 0;
    } else{
        return 1;
    }
}

int Queue_isEmpty(Queue * self){
    if(List_isEmpty(self->l)){
        return 1;
    }

    return 0;
}

int  Queue_count(Queue * self){
    return List_count(self->l);
}

// void Queue_clear(Queue * self);
// void Queue_print(Queue* self);