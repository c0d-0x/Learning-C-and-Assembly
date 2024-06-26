#ifndef LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *data;
  struct node *next;
} node_t;

node_t *init_list(void);
size_t count_list(node_t *head);
void print_list(node_t *head, void (*f)(node_t *));
int insert_to_tail(node_t **head, void *data);
int insert_to_head(node_t **head, void *data);
node_t *delete_by_position(node_t **head, size_t position);
void *delete_by_data(node_t **head, void *data);
node_t *pop_head(node_t **head);
node_t *break_tail(node_t **head);
void destroy_list(node_t **head);
#endif // !LINKED_LIST_H
