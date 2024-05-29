#include "linked_list.h"
#include <stdio.h>

node_t *init_list(void) { return (node_t *)NULL; }

size_t count_list(node_t *head) {
  size_t num = 0;
  node_t *node;
  node = head;

  while (node != NULL) {
    node = node->next;
    num++;
  }
  return num;
}

void print_list(node_t *head) {
  node_t *node;
  node = head;

  while (node != NULL) {
    printf("Data: %s\n", (char *)node->data);
    node = node->next;
  }
}

int insert_to_head(node_t **head, void *data) {

  node_t *node = NULL;
  if ((node = (node_t *)malloc(sizeof(node_t))) == NULL) {
    perror("Malloc Failed");
    return -1;
  }

  node->data = data;
  node->next = (*head);
  (*head) = node;
  return 0;
}

int insert_to_tale(node_t **head, void *data) {

  if ((*head) == NULL) {
    insert_to_head(head, data);
    return 0;
  }

  node_t *current, *node = NULL;
  if ((node = (node_t *)malloc(sizeof(node_t))) == NULL) {
    perror("Malloc Failed");
    return -1;
  }

  node->data = data;
  current = (*head);

  while (current->next != NULL) {
    current = current->next;
  }

  node->next = current->next;
  current->next = node;
  return 0;
}

node_t *pop_head(node_t **head) {

  if ((*head) == NULL) {
    return NULL;
  }

  node_t *node = (*head);
  (*head) = (*head)->next;
  node->next = NULL;
  return node;
}

node_t *break_tale(node_t **head) {
  if ((*head) == NULL) {
    return NULL;
  }

  node_t *prev = (*head);
  node_t *node = (*head);
  while (node->next != NULL) {
    prev = node;
    node = node->next;
  }

  if (prev != node)
    prev->next = NULL;
  else
    (*head) = NULL;

  return node;
}

void *delete_by_position(node_t **head, size_t position) {

  if ((*head) == NULL) {
    return NULL;
  }

  void *data = NULL;
  node_t *prev = NULL, *node = (*head);
  size_t i = 1;
  while (node != NULL && i < position) {
    i++;
    prev = node;
    node = node->next;
  }

  if (node != NULL) {
    prev->next = node->next;
    data = node->data;
    free(node);
  }
  return data;
}

// void *delete_by_data(node_t *head, void *data) {
//   //[TODO]: search for data then delete
// }
//

void distroy_list(node_t **head) {
  node_t *node;
  while ((*head) != NULL) {
    node = (*head);
    (*head) = (*head)->next;
#ifdef DATA_ALLOCATED
    free(node->data); /* only of data allocated data from the heap*/
#endif                /* ifdef DATA_ALLOCATED */
    free(node);
  }
}
