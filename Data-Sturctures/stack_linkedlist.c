#include<stdio.h>
#include <stdlib.h>
typedef struct stack{
    int num;
    struct stack *next;
} stck;

int isempty(stck ** headptr){
    if(headptr == NULL)
        return 2;
    else
        return 1;  
}

int pop(stck **headptr){
    int numb;
    if(!isempty(headptr)){
        if ((*headptr)->next == NULL){
            numb = (*headptr)->num;
            free(*headptr);
        }else {
            stck *tmp = malloc(sizeof(stck));
            tmp = (*headptr)->next;
            numb = (*headptr)->num;
            free(*headptr);
            (*headptr) = tmp;
        }
    }else {
        fprintf(stderr,"Error: the stack is empty");
        exit(2);
    }
    return numb;
}

void push(stck **headptr, int numb){
    if(!isempty(headptr)){
        stck* tmp = malloc(sizeof(stck));
        tmp->num = numb;
        tmp->next = (*headptr);
        (*headptr) = tmp;
    }
}

void peek(stck *headptr){
    if(!isempty(&headptr)){
        printf("Top of the Stack: %d\n", headptr->num);
    }
}
stck *stackinit(void){
    stck * tmp = NULL;
    return tmp;
}

int main(void){
    stck *headptr = stackinit();
    // loading the stack...
    for(int i = 1; i < 10; i++){
        push(&headptr, i+2);

    }    
    peek(headptr);   
    int a = pop(&headptr);
    printf("poped: a = %d\n", a);
    peek(headptr);   
    return 0;
}
