
#include <stdio.h>
#include <stdlib.h>
#include "q.h"
#include "threads.h"

// void (*testFunc)();
// testFunc = test;
// (*testFunc)(3);
int main(){


    struct Queue *linkedList;
    initQueue(linkedList);

    for (int i = 0; i < 10; i++){ 
        struct TCB_t* item = newTCB(i);
        AddQueue(linkedList,item);
    }
    // // // write a function printQ to print the Queue//

    printQ(linkedList);  // should output: 0 1 2 3 4 5 6 7 8 9

    for (int i = 0; i < 5; i++){
        struct TCB_t* item = DelQueue(linkedList);
        printf("Item Deleted %d \n", item->payload); // output should be 0 1 2 3 4
    }
    printQ(linkedList);
    RotateQ(linkedList);
    struct TCB_t* item = DelQueue(linkedList);
    printf("item Deleted %d \n", item->payload); // output should be 6
    
    return 0;
}
