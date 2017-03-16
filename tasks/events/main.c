#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "events.h" 
#include <pbconsole.h>

/* custom constant event type ids*/
enum {
    KeyIsPressedTypeId,
    SomeoneJoinedChatTypeId,
    SomeoneLeftChatTypeId
};

/* event handler functions prototypes */
void UpdatePrintHandler_update(EventHandler * self, Event * event);
void InputHandler_update(EventHandler * self, Event * event);
void PeopleInRoomGenerator_update(EventHandler * self, Event * event);
void PeopleListHandler_update(EventHandler * self, Event * event);

int main(void) {
    srand(0);

    EventSystem_init();

    List* list = List_new();
    int* personsID = (int*)malloc(sizeof(int));

    EventSystem_addHandler(EventHandler_new(NULL, NULL, UpdatePrintHandler_update));
    EventSystem_addHandler(EventHandler_new(NULL, NULL, InputHandler_update));
    EventSystem_addHandler(EventHandler_new(personsID, free, PeopleInRoomGenerator_update));
    EventSystem_addHandler(EventHandler_new(list, List_freeAll, PeopleListHandler_update));

    EventSystem_loop();
    EventSystem_cleanup();

    return 0;
}

/* event handlers functions implementations */

void UpdatePrintHandler_update(EventHandler * self, Event * event) {
    switch (event->type) {
        case StartEventTypeId: {
            printf("\nChat started. Try pressing [1], [2], [3], [4], [5].\n");
            break;
        }
        case ExitEventTypeId: {
            printf("\nGoodbye!\n");
            break;
        }
    }
}


void InputHandler_update(EventHandler * self, Event * event){
    if (conIsKeyDown()) {  // non-blocking key input check
        char * keyCode = malloc(sizeof(int));
        fflush(stdin);
        *keyCode = getchar();
        if(*keyCode == 'q'){
            free(keyCode);
            EventSystem_exit();
        } else{
            EventSystem_raiseEvent(Event_new(self, KeyIsPressedTypeId, keyCode, free));
        }
    }
}

void PeopleInRoomGenerator_update(EventHandler * self, Event * event){
    if(event->type == KeyIsPressedTypeId){
        if(*((char*)event->data) == '1' || *((char*)event->data) == '3' || *((char*)event->data) == '5'){
            (*(int*)self->data)++;
            int *newID = (int*) malloc(sizeof(int));
            *newID = *((int*)(self->data));
            printf("\nNew ID is %i", *newID);
            EventSystem_raiseEvent(Event_new(self, SomeoneJoinedChatTypeId, newID, free));

        } else if(*((int*)event->data) == '2' || *((int*)event->data) == '4'){
            // (*(int*)self->data)++;
            // int* newID = (int*) malloc(sizeof(int));
            // *newID = *((int*)(self->data));
            // printf("\nNew ID is %i", *newID);
            EventSystem_raiseEvent(Event_new(self, SomeoneLeftChatTypeId, NULL, NULL));
        }
    }
}

void PeopleListHandler_update(EventHandler * self, Event * event){
    if(event->type == SomeoneJoinedChatTypeId){
        int* newID = (int*) malloc(sizeof(int));
        *newID = *((int*) event->data);
        List_add(self->data, newID);

        printf("\nID%i have joined chat\n", *newID);
        printf("This people are in chat now:");
        List_print(self->data);
        printf("\n\n");
    } else if(event->type == SomeoneLeftChatTypeId){
        if(List_isEmpty(self->data)){
            printf("\nThere`s nobody here\n\n");
        } else {
            int* randomID = (int*) malloc(sizeof(int));

            if(List_getSize(self->data) == 1){
                *randomID = 0;
            } else {
                *randomID = rand()%(List_getSize(self->data) - 1);
            }
            
            printf("\nRemoving someone wirh index %i", *randomID);
            printf("\nID%i had left the chat\n", *((int*)List_get(self->data, *randomID)));

            List_removeAt(self->data, *randomID);
            printf("This people are in chat now:");
            List_print(self->data);
            printf("\n\n");
            
            free(randomID);
        }
    }
}

