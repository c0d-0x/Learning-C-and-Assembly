#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHMAX 10
char *hash_table[HASHMAX];

unsigned int hash_func(const char *name) {
  size_t stringlen = strnlen(name, HASHMAX);
  int hash_value = 0;
  for (size_t i = 0; i < stringlen; i++) {
    hash_value += name[i];
    hash_value = (hash_value + name[i]) % HASHMAX;
  }

  return hash_value;
}

void insert_hashtable(char *name) {

  size_t hash_index = hash_func(name);

  if (hash_table[hash_index] == NULL) {
    hash_table[hash_index] = name;
  }
}
void print_table(void) {
  for (size_t i = 0; i < HASHMAX; i++) {
    if (hash_table[i] == NULL)
      printf("_____\t%ld\n", i);
    else
      printf("%s\t%ld\n", hash_table[i], i);
  }
}
void hash_init(void) {
  for (size_t i = 0; i < HASHMAX; i++) {
    hash_table[i] = NULL;
  }
}
int main(int argc, char *argv[]) {
  hash_init();
  insert_hashtable("Cronux");
  insert_hashtable("Zeus");
  insert_hashtable("Fuzz");
  insert_hashtable("Draxes");
  insert_hashtable("Bacox");
  print_table();
  return EXIT_SUCCESS;
}
