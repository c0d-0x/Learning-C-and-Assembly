#include <stdio.h>
#include <stdlib.h>
/* This was implememted for more understanding of memeory safety with malloc. */
typedef struct Node {
    int value;
    struct Node * next;
} Node ;

void insert_end(Node ** root, int value){
    Node * new_node = malloc(sizeof(Node));
    if (new_node == NULL){
        exit(1);
    }
    new_node->value = value;
    if (*root == NULL) {
        new_node->next = *root;
        *root = new_node;
        return;
    }
    Node * tmp = *root;
    while (tmp->next != NULL ) {
        tmp = tmp->next;
    }
    new_node->next = NULL;
    tmp->next = new_node;

}
void insert_head(Node ** head, int value){
    Node * new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}
void printlist(Node * head){
    Node * tmp = head;
    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

int main(){
    Node * head;
    head = NULL;
    insert_end(&head, 3);
    insert_end(&head, 4);
   insert_head(&head, 2); 
   insert_head(&head, 1); 
   insert_head(&head, 0); 
    printlist(head);


}
