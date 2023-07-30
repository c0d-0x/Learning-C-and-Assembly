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

    if ((*head) == NULL){
    tmp->elem = value;
    tmp->next = (*head);
    (*head) = tmp;
    } 


}
