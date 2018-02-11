
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "threads.h"

// void (*testFunc)();
// testFunc = test;
// (*testFunc)(3);
int main(){
    
    RunQ = (struct Queue*)malloc (sizeof (struct Queue));
    RunQ->head = NULL;

    for (int i = 0; i < 10; i++){ 
        struct TCB_t* item = newTCB(i);
        AddQueue(RunQ,item);
    }
    // // // write a function printQ to print the Queue//

    printQ(RunQ);  // should output: 0 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < 5; i++){
        struct TCB_t* item = DelQueue(RunQ);
        printf("Item Deleted %d \n", item->payload); // output should be 0 1 2 3 4
    }
    printQ(RunQ);
    RotateQ(RunQ);
    struct TCB_t* item = DelQueue(RunQ);
    printf("item Deleted %d \n", item->payload); // output should be 6
    
    return 0;
}
