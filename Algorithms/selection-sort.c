#include <stdio.h>
#define TMAX 10

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int i, min, j, n = TMAX - 1;
  int array[TMAX] = {2, 5, 6, 3, 1, 10, 53, 4, 8, 12};

  for (i = 0; i < n; i++) {
    min = i;
    for (j = min; j < TMAX; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }

    if (min != i) {
      swap(&array[min], &array[i]);
      printf("[%d] Swaped ( %d, %d )\n", i, array[min], array[i]);
    }
  }
  printf("\nSorted Array: ");
  for (i = 0; i < TMAX; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
