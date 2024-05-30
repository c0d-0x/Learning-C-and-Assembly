#include "src/linked_list.h"
#include <stdio.h>

void print(node_t *node) { printf("data: %s\n", (char *)node->data); }

int main(void) {

  node_t *head = init_list();
  char data0[] = "Hello there 7";
  char data1[] = "Hello there 6";
  char data2[] = "Hello there 5";
  char data3[] = "Hello there 4";
  char data4[] = "Hello there 3";
  char data5[] = "Hello there 2";
  char data6[] = "Hello there 1";

  insert_to_head(&head, data0);
  insert_to_head(&head, data1);
  insert_to_head(&head, data2);

  insert_to_tale(&head, data3);
  insert_to_tale(&head, data4);
  insert_to_tale(&head, data5);

  delete_by_position(&head, 5);
  insert_to_tale(&head, data6);
  delete_by_position(&head, 6);

  node_t *popped = pop_head(&head);
  node_t *breaked = break_tale(&head);
  printf("Popped: %s\nBreaked: %s\n", (char *)popped->data,
         (char *)breaked->data);
  print_list(head, print);

  printf("<< %ld ELEMENTS OF SIZE %ld >>\n", count_list(head), sizeof(node_t));

  free(popped);
  free(breaked);
  distroy_list(&head);
  return EXIT_SUCCESS;
}
