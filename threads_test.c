
// #define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "threads.h"




void infinLoop1(){
    int i = 0;
    for(;;){
        printf("%i\n", i);
        i++;

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
        yield();
    }
}


int main(){
    // initQueue(RunQ);
    RunQ = (struct Queue*)malloc (sizeof (struct Queue));
    RunQ->head = NULL;
    


    start_thread(infinLoop1,1);
    start_thread(infinLoop2,2);


    run();

    return 1;
}