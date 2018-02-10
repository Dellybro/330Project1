
#include <stdio.h>
#include <stdlib.h>

struct Queue *RunQ;

void start_thread(void (*function)(void)){

}

void run(){
    ucontext_t parent; // get a place to store the main context, for faking
    getcontext(&parent); // magic sauce
    swapcontext(&parent, &(RunQ->head->context)); // start the first thread
}

void yield(){
//    rotate the run Q;
//    swap the context, from previous thread to the thread pointed to by RunQ
}
