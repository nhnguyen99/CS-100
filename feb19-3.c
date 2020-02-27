#include <stdio.h>

void rotate(int *, int *, int *);
int main(void) {
  int a = 10, b = 20, c = 30;
  printf("%d and %d and %d\n", a, b, c);

  rotate(&a, &b, &c);
  printf("%d and %d and %d\n", a, b, c);

  rotate(&a, &b, &c);
  printf("%d and %d and %d\n", a, b, c);

  rotate(&a, &b, &c);
  printf("%d and %d and %d\n", a, b, c);

  return 0;
}
void rotate(int *x, int *y, int *z) {
  int temp = *x;
  *x = *y;
  *y = *z;
  *z = temp;
  return;
}
