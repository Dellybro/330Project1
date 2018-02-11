/**
 * CSE 330 Assignment 1 Threading using TCB's
 * Travis Delly
 * 1210230252
 * 
*/

// #define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "threads.h"


void infinLoop1(){
    int i = 0;
    for(;;){
        printf("InfinLoop1 Loop #%i\n", i);
        i++;
        global++;
        yield();
    }
}
void infinLoop2(){
    int i = 0;
    for(;;){
        if(i % 2 == 0){
            printf("Mouse\n");
        } else if(i % 3 == 0){
            printf("Whale\n");
        } else {
            printf("Tiger!\n");
        }
        i++;
        global++;
        yield();
    }
}

void infinLoop3(){
    for(;;){
        global++;
        printf("Total Context switches %i\n", global);
        yield();
    }
}


int main(){
    // initQueue(RunQ);
    RunQ = (struct Queue*)malloc (sizeof (struct Queue));
    RunQ->head = NULL;
    


    start_thread(infinLoop1,1);
    start_thread(infinLoop2,2);
    start_thread(infinLoop3,3);


    run();

    return 1;
}