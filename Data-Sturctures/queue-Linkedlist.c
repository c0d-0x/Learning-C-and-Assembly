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
// adding a node to the head of the list.
    tmp->next = *head;
    *head = tmp;
}

int dequeue(queue_t **head){
    int Dval;
    if((*head)->next == NULL){
        Dval = (*head)->elem;
        free(*head);
        *head = NULL;
        return Dval;
    }
    queue_t * tmp = *head, *prev;
    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    Dval = tmp->elem;
    free(tmp);
    prev->next = NULL;
    return Dval;
}

int main(){
    queue_t *head = NULL;
    enqueue(&head, 0);
    enqueue(&head, 1);
    enqueue(&head, 2);
    enqueue(&head, 3);
    enqueue(&head, 4);
    enqueue(&head, 5);
    for (int i = 0; i < 5; i++) {
        fprintf(stdout,"%d\n", dequeue(&head)); 
    }
    return 0;
}
