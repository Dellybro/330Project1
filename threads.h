
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

struct Queue *RunQ;

void start_thread(void (*function)(void), int threadId){
//  begin pseudo code
//      allocate a stack (via malloc) of a certain size (choose 8192)
//      allocate a TCB (via malloc)
//      call init_TCB with appropriate arguments
//      call addQ to add this TCB into the “RunQ” which is a global header pointer
//  end pseudo code

    void *stack = malloc(8192);
    struct TCB_t* item = newTCB(threadId);
    init_TCB(item, function,stack, 8192);
    AddQueue(RunQ,item);
}


void run(){
    ucontext_t parent; // get a place to store the main context, for faking
    getcontext(&parent); // magic sauce
    swapcontext(&parent, &(RunQ->head->context)); // start the first thread
}

void yield(){
//  rotate the run Q;
//  swap the context, from previous thread to the thread pointed to by RunQ
    ucontext_t previousQueue;
    getcontext(&previousQueue);
    RunQ->head->context = previousQueue;

    RotateQ(RunQ);
    swapcontext(&previousQueue, &(RunQ->head->context));
}
