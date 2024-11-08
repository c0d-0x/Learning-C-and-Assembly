#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  size_t i, len;
  char cc;
  FILE *fp = NULL;

  if (argc != 2) {
    printf("%s <filename or a string in quotes>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (access(argv[1], F_OK) != 0 && argv[1] != NULL) {
    len = strlen(argv[1]);
    for (i = 0; i < len; i++) {
      printf("\\x%02x", argv[1][i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
  }

  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("Failed to open file: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  while (1) {
    cc = getc(fp);
    if (cc == EOF) {
      break;
    }
    printf("\\x%02x", cc);
  }

  printf("\n");
  return EXIT_SUCCESS;
}
