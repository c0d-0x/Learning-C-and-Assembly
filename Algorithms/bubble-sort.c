#include <stdbool.h>
#include <stdio.h>
#define TMAX 10

void swap(const void *a, const void *b) {
  // Practicing with void pointers
  int tmp = (*(int *)a);
  (*(int *)a) = (*(int *)b);
  (*(int *)b) = tmp;
}

int main() {
  int j = TMAX - 1, i;
  bool sorted = true;

  int array[TMAX] = {2, 5, 6, 3, 1, 10, 53, 4, 8, 12};

  while (j > 0 && sorted) {
    sorted = false;
    for (i = 0; i < j; i++) {
      if (array[i] > array[i + 1]) {
        swap(&array[i], &array[i + 1]);
        sorted = true;
      }
    }
    j--;
  }
  printf("Sorted Array: [");
  for (i = 0; i < TMAX; i++) {
    printf("%d", array[i]);
    if (i <= TMAX - 2) {
      printf(", ");
    } else {
      printf("]\n");
    }
  }
  return 0;
}
