
#include <stdio.h>
#include <stdlib.h>

struct Queue *RunQ;

void start_thread(void (*function)(void)){
// begin pseudo code
//      allocate a stack (via malloc) of a certain size (choose 8192)
//      allocate a TCB (via malloc)
//      call init_TCB with appropriate arguments
//      call addQ to add this TCB into the “RunQ” which is a global header pointer
//end pseudo code
}

void run(){
    // ucontext_t parent; // get a place to store the main context, for faking
    // getcontext(&parent); // magic sauce
    // swapcontext(&parent, &(RunQ->head->context)); // start the first thread
}

void yield(){
//    rotate the run Q;
//    swap the context, from previous thread to the thread pointed to by RunQ
}
