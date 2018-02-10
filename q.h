
#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

#if !defined(NULL)
    #define NULL ((void*)0)
#endif

struct TCB_t *newTCB(int payload){
    struct TCB_t* node = (struct TCB_t*)malloc (sizeof (struct TCB_t));
    node->payload = payload;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/* Sets up the queue? */
void initQueue(struct Queue *list){
    list = (struct Queue*)malloc (sizeof (struct Queue));
}

/* Deletes head of queue */
struct TCB_t *DelQueue(struct Queue *list){
    struct TCB_t* previousHead = list->head;
    if(!previousHead->next){
        list->head = NULL;
        return previousHead;
    }

    struct TCB_t* tail = previousHead->prev;
    struct TCB_t* newHead = previousHead->next;
    
    //Make head = to head->next
    //make new head prev = to previousHead previous
    //Make the last node next = to new list head
    tail->next = newHead;
    newHead->prev = tail;
    list->head = newHead;


    previousHead->next = NULL;
    previousHead->prev = NULL;

    return previousHead;
}

/* Adds to tail. */
void AddQueue(struct Queue *list, struct TCB_t *newItem){
    printf("Adding queue1\n");
    if(!list->head){
        printf("Adding queue2\n");
        list->head = newItem;
        printf("Adding queue3\n");
        return;
    } 
    printf("Adding queue4\n");
    struct TCB_t *current = list->head;
    if(!current->next){
        current->next = newItem;
        current->prev = newItem;
        newItem->next = current;
        newItem->prev = current;
    } else {
        while(current->next != list->head){
            current = current->next;
        }

        current->next = newItem;
        newItem->prev = current;
        newItem->next = list->head;
        list->head->prev = newItem;
    }
    
}


/* counter clock wise, 123 becomes 231, use delqueue to pop off 1 and than put it at tail of queue */
void RotateQ(struct Queue *list){
    struct TCB_t *deleted = DelQueue(list);
    AddQueue(list, deleted);
}

void printQ(struct Queue *list){
    struct TCB_t *current = list->head;
    /* Make sure current isn't null */
    if(!current){
        return;
    }else if(!current->next){
        /* if no next, only print current payload */
        printf("Current: %i \n", current->payload);
    } else {
        /* Loop until current next is head while printing */
        while(current->next != list->head){
            printf("Current: %i \n", current->payload);
            current = current->next;
        }
        printf("Current: %i \n", current->payload);
    }
}