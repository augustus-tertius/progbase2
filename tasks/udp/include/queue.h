
typedef struct Queue Queue;

Queue * Queue_new(void);

void Queue_free(Queue ** self); 
void * Queue_getAt(Queue * self, int index);
void Queue_add(Queue * self, void * ref);
int Queue_removeFirst(Queue * self);
int Queue_isEmpty(Queue * self);
int  Queue_count(Queue * self);
void Queue_clear(Queue * self);
void Queue_print(Queue* self);
