#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <progbase/net.h>
#include <ctype.h>
#include <string.h>
#include <queue.h>

#define BUFFER_LEN 1024
#define STR_COUNT 5

typedef struct ClientRequest {
    char action [100];
    char str [200];
} ClientRequest;

ClientRequest parseRequest (const char * msgStr);

int main(void) {
    // queue <string> sQueue;
    Queue* sQueue = Queue_new();

    UdpClient * server = UdpClient_init(&(UdpClient){});
    IpAddress * address = IpAddress_initAny(&(IpAddress){}, 9998);
    if (!UdpClient_bind(server, address)) {
        perror("Can't start server");
        return 1;
    }
    printf("Udp server started on port %d\n", 
        IpAddress_port(UdpClient_address(server)));
    
    printf("\
    count -- get number of strings\n\
    add -- add new string to queue\n\
    get -- see fist string in queue\n\
    all -- see all strings in queue\n\
    delete -- removes first element in queue");

    NetMessage * message = NetMessage_init(
        &(NetMessage){},  // value on stack
        (char[BUFFER_LEN]){},  // array on stack 
        BUFFER_LEN);

    IpAddress clientAddress;

    int isOpened = 1;

    while (isOpened) {
        puts("Waiting for data...");

        if(!UdpClient_receiveFrom(server, message, &clientAddress)) {
			perror("recv");
			return 1;
		}

        ClientRequest request = parseRequest(message->buffer);

        // count, add, get, all, delete

        if(0 == strcmp(request.action, "count")){
            char buf [200] = "\0";
            sprintf(buf, "\nnumber of strings in queue is %i", Queue_count(sQueue));
            NetMessage_setDataString(message, buf);
            message->dataLength = strlen(message->buffer);
        } else if(0 == strcmp(request.action, "add")){
            char * ref = malloc(sizeof(char)*200);
            strcpy(ref, request.str);
            Queue_add(sQueue, ref);

            char buf [250] = "\nadding string:  ";
            strcat(buf, request.str);
            NetMessage_setDataString(message, buf);
        } else if(0 == strcmp(request.action, "get")){
            char buf [250] = "\nfirst string in the queue is:  ";
            char* str = Queue_getAt(sQueue, 0);
            printf("%s", str);
            strcat(buf, str);
            NetMessage_setDataString(message, buf);
        } else if(0 == strcmp(request.action, "all")){
            char buf [1000] = "\nstrings in the queue: \n ";
            for(int i = 0; i < Queue_count(sQueue); i++){
                strcat(buf, Queue_getAt(sQueue, i));
            }
            NetMessage_setDataString(message, buf);
        } else if(0 == strcmp(request.action, "delete")) {
            if(!Queue_isEmpty(sQueue)){
                char buf [250] = "\nremoving first string:  ";
                strcat(buf, Queue_getAt(sQueue, 0));
                Queue_removeFirst(sQueue);
                NetMessage_setDataString(message, buf);
            } else {
                NetMessage_setDataString(message, "\nqueue is already empty");
            }
        } else {
            printf("%s, %s", request.action, request.str);
            NetMessage_setDataString(message, "invalid");
        }


        printf("Received message from %s:%d (%d bytes): `%s`\n",
            IpAddress_address(&clientAddress),  // client IP-address
            IpAddress_port(&clientAddress),  // client port
            NetMessage_dataLength(message),
            NetMessage_data(message));

        //
        // send echo response
        if (!UdpClient_sendTo(server, message, &clientAddress)) {
			perror("send");
			return 1;
		}
    }
    //
    // close server
    Queue_free(&sQueue);
    UdpClient_close(server);
	return 0;
}

ClientRequest parseRequest (const char * msgStr){
    ClientRequest request = {
        .action = "\0",
        .str = "\0"
    };

    int chIndex = 0;

    while (isalpha(msgStr[chIndex])){
            chIndex++;
    }

    strncpy(request.action, msgStr, chIndex);
    // request.action[chIndex] = '\0';

    strncpy(request.str, msgStr + chIndex, 200 - chIndex);
    request.str[199] = '\0';
    // char* next = NULL;

    return request;
}