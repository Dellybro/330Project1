
#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"


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
    if(previousHead->next == NULL){
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
    if(list->head == NULL){
        list->head = newItem;
        return;
    } 

    struct TCB_t *current = list->head;
    if(current->next == NULL){
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
    if(current == NULL){
        return;
    }else if(current->next == NULL){
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