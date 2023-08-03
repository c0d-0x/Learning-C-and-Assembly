#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct queue_t{
    int elem;
    struct queue_t *next;
} queue_t;

void enqueue(queue_t** head, int value){
    queue_t* tmp;
    tmp = malloc(sizeof(queue_t));
    tmp->elem = value;

    if ((*head) == NULL){
       tmp->next = (*head);
    (*head) = tmp;
    }else {
    queue_t *prev;
    prev = (*head);
    
    while (prev->next != NULL) {
    prev = prev->next;
    }   
    tmp->next = prev->next;
    prev->next = tmp;

    } 


}
