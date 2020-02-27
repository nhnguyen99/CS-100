#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int a, b;

    int **matrix = malloc(sizeof(int*)*5);
    for (a = 0; a < 5; a++)
      matrix[a] = malloc(sizeof(int)*10);

    for (a = 0; a< 5; a++)
      for (b = 0; b < 10; b++) matrix[a][b] = a+b;

    for (a = 0; a< 5; a++) {
      for (b = 0; b < 10; b++) printf("%2d", matrix);
      printf("\n");
    }
}
