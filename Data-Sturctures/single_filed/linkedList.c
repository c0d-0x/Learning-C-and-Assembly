#include <stdio.h>
#include <stdlib.h>

// Declaration of the node.
typedef struct node{
    int val;
    struct node * next;
} node_t;

// Prototypes
void print_list(node_t* );
void push(node_t*, int);
void newNode(node_t**, int);
int  popHead( node_t** );
int  initList(node_t**, int);
int  removeLast(node_t* );
int  removebyValue(node_t**, int );
// void removeAllof(node_t**, int);

int  main(void){

    node_t * head = NULL;
    initList(&head, 1);

    for (int i = 1; i < 10; i++) {
        push(head, i+1);
    }
    newNode( &head, 9);
    newNode( &head, 1);
    newNode( &head, 1);
    popHead(&head);
    removebyValue(&head, 4);
    removebyValue(&head, 1);
    removebyValue(&head, 9);
    removeLast(head);
    removebyValue(&head, 1);
    /* removeAllof(&head, 9); */
    print_list(head); 

    return 0;
}



void print_list(node_t* L){
    node_t * tmp;
    tmp = L;

    while (tmp != NULL) {

        printf("%d\n", tmp->val);
        tmp = tmp->next;

    }
}


void push(node_t* L, int value){

    node_t* tmp = L;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = malloc(sizeof(node_t)); 
    tmp->next->val = value;
    tmp->next->next = NULL;
}


int initList( node_t ** headptr, int value){
    *headptr = malloc(sizeof(node_t));
    if(headptr == NULL){
        return -1;
    }
    (*headptr)->val = value;
    (*headptr)->next = NULL;

    return 1;
}



void newNode(node_t ** head, int value){
    node_t * newval;
    newval = malloc(sizeof(node_t));
    newval->val = value;
    newval->next = (* head);
    (*head) = newval;
}


int popHead(node_t** head){

    if ((*head) == NULL){
        return -1;
    }

    node_t * tmp = NULL;
    tmp = malloc(sizeof(node_t));
    tmp = ((*head))->next;
    free(*head);
    ((*head)) = tmp;

    return 1;
}

int removeLast(node_t * headptr){
    int result;    
    if(headptr != NULL){
        if(headptr->next ==NULL){
            result = headptr->val;
            free(headptr);
            return result;
        }
        node_t * temp = headptr;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        result = temp->next->val;
        free(temp->next);
        temp->next = NULL;
    }
    return result;
}


int removebyValue(node_t** headptr, int value){
    int removed;
    node_t *temp, *prev;
    if ((*headptr)->val == value){
        return popHead(headptr);
    }
    temp = *headptr;
    prev = *headptr;

    while (temp != NULL) {
        if(temp->val == value){
            removed = temp->val;
            prev->next = temp->next;
            free(temp);
            /* break; */ // for just the first occurance
            temp = prev;
        }
        prev = temp;
        temp = temp->next;

    }
    return removed;

}         

void removeAllof(node_t** headptr, int value) {
    node_t* current = *headptr;
    if (current == NULL) {
        return; // Base case: reached the end of the list
    }

    if (current->val == value) {
        *headptr = current->next; // Update the head pointer to skip the current node
        free(current); // Free the memory of the current node
        removeAllof(headptr, value); // Recursively call removeAllof with the updated headptr
    } else {
        removeAllof(&(current->next), value); // Recursively call removeAllof with the next node
    }
}

