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



/* prints the values of the list. */
void print_list(node_t* L){
    // creating a temp variable...
    node_t * tmp;
    tmp = L;

    while (tmp != NULL) {

        printf("%d\n", tmp->val);
        tmp = tmp->next; // pointing to the next item.

    }
}


/* Pushes a value to the end of the list */
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
    // error free
    *headptr = malloc(sizeof(node_t));
    if(headptr == NULL){
        return -1;
    }
    (*headptr)->val = value;
    (*headptr)->next = NULL;

    return 1;
}

/* To add to the beginning of the list, we will need to do the following: 
   1. Create a new item and set its value 
   2. Link the new item to point to the head of the list 
   3. Set the head of the list to be our new item */

/*  The address of the pointer it self must be passed to the 
    function in other to be able to manuplate is. */

void newNode(node_t ** head, int value){
    node_t * newval;
    newval = malloc(sizeof(node_t));
    newval->val = value;
    newval->next = (* head);
    (*head) = newval;
}

/*Removing the first item (popping from the list)
  To pop a variable, we will need to reverse this action:

  1. Take the next item that the head points to and save it
  2. Free the head item
  3. Set the head to be the next item that we've stored on the side*/

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

// Removing the last element of the list

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
            /* break; */
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

